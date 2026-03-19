#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define pii pair<int, int>

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m; cin>>n>>m;
    vec<vec<int>> adj(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vec<int> vis(n+1, -1);
    int ans = 0;
    for (int i = 1; i < n+1; i++) {
        if(vis[i]>=0)continue;
        vis[i] = 0;
        queue<int> bfs;
        bfs.push(i);
        vec<int> par(2);
        bool ok = 1;
        while(!bfs.empty()){
            int c = bfs.front(); bfs.pop();
            par[vis[c]]++;
            for(auto &e:adj[c]){
                if(vis[c] == vis[e])ok = 0;
                if(vis[e]<0){
                    vis[e] = vis[c]^1;
                    bfs.push(e);
                }
            }
        }
        if(ok)ans+=ranges::max(par);
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


