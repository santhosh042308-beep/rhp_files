#include <bits/stdc++.h>

using namespace std;

int main() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int a = s1.length(), b = s2.length(), mx = 0;
    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                mx = max(mx, dp[i][j]);
            }
        }
    }
    cout << mx << endl;
    return 0;
}
