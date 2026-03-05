#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void joseph(vec<int> &c){
    if(c.size()==1)return void(cout<<c[0]<<endl);
    for (int i = 1; i < c.size(); i+=2) {
        cout<<c[i]<<' ';
    }
    vec<int> nc;
    if(c.size()&1)nc.push_back(c.back());
    for (int i = 0; i < (int)c.size()-1; i+=2) {
        nc.push_back(c[i]);
    }
    joseph(nc);
}
  
void solve(){
    int n; cin>>n;
    vec<int> c(n);
    iota(c.begin(), c.end(), 1);
    joseph(c);
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


