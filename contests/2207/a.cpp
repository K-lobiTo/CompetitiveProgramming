#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    int ones = 0;
    int initial = 0;
    for(auto &c:s)initial += c=='1';
    for (int i = 1; i < n-1; i++) {
        if(s[i-1] == s[i+1] && s[i+1] == '1' && s[i]!='1'){
            s[i] = '1';
            ones++;
        }
    }
    int ceros = 0;
    int initial2 = 0;
    for(auto &c:s)initial2 += c=='1';
    for (int i = 1; i < n-1; i++) {
        if(s[i-1] == s[i+1] && s[i+1] == '1' && s[i]!='0'){
            s[i] = '0';
            ceros++;
        }
    }
    cout<<initial2-ceros<<" "<<initial+ones<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


