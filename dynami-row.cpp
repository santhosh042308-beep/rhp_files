#include <bits/stdc++.h>

using namespace std;

void solve(){
    int R, C;
    if (!(cin >> R >> C)) return 0;

    vector<vector<int>> grid(R, vector<int>(C));
    vector<vector<long long>> dp(R, vector<long long>(C, 0));

    for (int row = 0; row < R; row++) {
        for (int col = 0; col < C; col++) {
            cin >> grid[row][col];
            if (row == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int row = 1; row < R; row++) {
        long long fmax = dp[row - 1][0];
        long long smax = 0;
        
        if (C > 1) {
            fmax = max(dp[row - 1][0], dp[row - 1][1]);
            smax = min(dp[row - 1][0], dp[row - 1][1]);
            for (int col = 2; col < C; col++) {
                if (dp[row - 1][col] > fmax) {
                    smax = fmax;
                    fmax = dp[row - 1][col];
                } else if (dp[row - 1][col] > smax) {
                    smax = dp[row - 1][col];
                }
            }
        }

        for (int col = 0; col < C; col++) {
            dp[row][col] = grid[row][col] + (dp[row - 1][col] == fmax ? smax : fmax);
        }
    }

    long long final_max = dp[R - 1][0];
    if (C > 1) {
        long long final_smax = min(dp[R - 1][0], dp[R - 1][1]);
        final_max = max(dp[R - 1][0], dp[R - 1][1]);
        for (int col = 2; col < C; col++) {
            if (dp[R - 1][col] > final_max) {
                final_smax = final_max;
                final_max = dp[R - 1][col];
            } else if (dp[R - 1][col] > final_smax) {
                final_smax = dp[R - 1][col];
            }
        }
    }

    cout << final_max << "\n";

    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while(tc--) solve();
    return 0;
}
