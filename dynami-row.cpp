#include <iostream>
using namespace std;
void combi(string s){
    int l=s.length();
    for(int ctr=1;ctr<(1<<l);ctr++){
        string comb="";
        for(int ch=0;ch<l;ch++){
            if((ctr & (1<<ch))>0)
                comb+=s[ch];
        }
        cout<<comb<<endl;
    }
}
int main(){
    string s;
    cin>>s;
    combi(s);
    return 0;
}
