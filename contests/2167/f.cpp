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
    int n, k; cin>>n>>k;
    vec<vec<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin>>u>>v; u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vec<int> sz(n, 1);

    auto dfs = [&] (auto &dfs, int v, int p) -> void {
        for(int u:adj[v]){
            if(u!=p){
                dfs(dfs, u, v);
                sz[v]+=sz[u];
            }
        }
    };

    ll ans = n;
    dfs(dfs, 0, -1);
    for (int i = 0; i < n; i++) {
        if(n - sz[i] >= k)ans += sz[i];
        if(sz[i] >= k) ans += n - sz[i];
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


