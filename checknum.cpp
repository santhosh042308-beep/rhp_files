#include <iostream>
using namespace std;
void solve(){
    string s; cin >> s;
    int digits = 0;
    for(char c : s){
        if(c >= '0' && c <= '9'){
            digits |= (1 << (c - '0'));
        }
    }
    cout << (digits == ((1 << 10) - 1) ? "Yes" : "No")<<endl;
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
