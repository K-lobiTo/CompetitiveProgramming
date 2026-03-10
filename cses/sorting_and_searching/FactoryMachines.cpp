#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
  
void solve(){
    ll n, t; cin>>n>>t;
    vec<ll> k(n); for(auto &e:k)cin>>e;
    ll l = 0, r = 1e18;
    while(l+1<r){
        ll m = (l+r)/2LL;
        ll cur = 0;
        for (int i = 0; i < n; i++) {
            cur += m/k[i];
            if(cur >= t)break;
        }
        if(cur >= t)r = m;
        else l = m;
    }
    cout<<r<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    int t=1;

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


