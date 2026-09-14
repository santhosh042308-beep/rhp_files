#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> getFSMax(const vector<vector<long long>>& dp, int row, int C) {
    if (C == 1) {
        return {dp[row][0], 0};
    }
    long long fmax = max(dp[row][0], dp[row][1]);
    long long smax = min(dp[row][0], dp[row][1]);
    for (int col = 2; col < C; col++) {
        if (dp[row][col] > fmax) {
            smax = fmax;
            fmax = dp[row][col];
        } else if (dp[row][col] > smax) {
            smax = dp[row][col];
        }
    }
    return {fmax, smax};
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

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
        vector<long long> fsmax = getFSMax(dp, row - 1, C);
        for (int col = 0; col < C; col++) {
            dp[row][col] = grid[row][col] + (dp[row - 1][col] == fsmax[0] ? fsmax[1] : fsmax[0]);
        }
    }

    vector<long long> final_max = getFSMax(dp, R - 1, C);
    cout << final_max[0] << "\n";

    return 0;
}
