#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<int> p(n); for(auto &e:p)cin>>e;
    int idxmax = n;
    for (int i = 0; i < n; i++) {
        if(p[i] == n){
            idxmax = i;
        }
    }
    int other = p[0];
    for (int i = 0; i < n; i++) {
        if(!i)cout<<p[idxmax]<<" ";
        else if(i == idxmax)cout<<other<<" ";
        else cout<<p[i]<<" ";
    }
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


