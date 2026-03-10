#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define pii pair<int, int>

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<pii> a(n);
    for(auto &[v, d]:a)cin>>v>>d;


    ranges::sort(a);
    ll ans = 0;
    ll acc = 0;
    for(auto &[v, d]:a){
        acc+=v;
        ans+=d-acc;
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


