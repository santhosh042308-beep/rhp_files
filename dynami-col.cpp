#include <bits/stdc++.h>

using namespace std;

void solve(){
    int R, C; cin >> R >> C;

    vector<vector<long long>> grid(R, vector<long long>(C));
    vector<vector<long long>> dp(R, vector<long long>(C));

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
            if (col == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int col = 1; col < C; col++) {
        long long fmax = -1, smax = -1;
        int fmax_row = -1;

        for (int row = 0; row < R; row++) {
            long long val = dp[row][col - 1];
            if (val > fmax) {
                smax = fmax;
                fmax = val;
                fmax_row = row;
            } else if (val > smax) {
                smax = val;
            }
        }

        for (int row = 0; row < R; row++) {
            if (row == fmax_row) {
                dp[row][col] = grid[row][col] + smax;
            } else {
                dp[row][col] = grid[row][col] + fmax;
            }
        }
    }

    long long ans = 0;
    for (int row = 0; row < R; row++) {
        ans = max(ans, dp[row][C - 1]);
    }

    cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while (tc--) solve(); 
    return 0;
}
