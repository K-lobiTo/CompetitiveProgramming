#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll x, n; cin>>x>>n;
    vec<ll> p(n); rAuto(p);
    set<int> lights; lights.insert(0); lights.insert(x);
    multiset<int> dist; dist.insert(x);
    vec<int> ans;

    for(auto e:p){
        auto it = lights.lower_bound(e);
        int r = *it, l = *prev(it);
        lights.insert(e);
        dist.erase(dist.find(r - l));
        dist.insert(r - e);
        dist.insert(e - l);

        ans.push_back(*dist.rbegin());
    }

    for(auto &e:ans)cout<<e<<' ';
        cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    while(t--){
        solve();
    }
    return 0;
}


