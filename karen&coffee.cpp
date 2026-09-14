#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n, k, q;
    cin >> n >> k >> q;

    int max_val = 200000;
    vector<int> diff(max_val + 2, 0);
    vector<int> pref(max_val + 2, 0);

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        diff[l]++;
        diff[r + 1]--;
    }

    int curr = 0;
    for (int i = 1; i <= max_val; i++) {
        curr += diff[i];
        pref[i] = pref[i - 1];
        if (curr >= k) {
            pref[i]++;
        }
    }

    while (q > 0) {
        int a, b;
        cin >> a >> b;
        cout << pref[b] - pref[a - 1] << "\n";
        q--;
    }

    return 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 1;
    while(tc--) solve();
    return 0;
}
