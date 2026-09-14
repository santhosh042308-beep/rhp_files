#include <bits/stdc++.h>

using namespace std;

void solve(){

    int n; cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    unordered_map<int, int> map;
    int sum = 0;
    int maxlen = 0;

    map[0] = -1; 

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            sum--;
        } else {
            sum++;
        }

        if (map.find(sum) != map.end()) {
            maxlen = max(maxlen, i - map[sum]);
        } else {
            map[sum] = i;
        }
    }

    cout << maxlen << "\n";

    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while(tc--) solve();
    return 0;
}
