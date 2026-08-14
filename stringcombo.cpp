#include <iostream>
using namespace std;
void solve(){
    string s; cin >> s;
    int L = s.length();
    for(int ctr = 1; ctr < (1 << L); ctr++){
        string subseq = "";
        for(int sh = 0; sh < L; sh++){
            if(ctr & (1 << sh)){
                subseq += s[sh];
            }
        }
        cout << subseq << endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tc = 1;
    while(tc--){
        solve();
    }
    return 0;
}
