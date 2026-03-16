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
    vec<bool> vis(n+1);
    for (int i = 0; i < m; i++) {
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vec<vec<int>> adjAns(n+1);
    for (int i = 1; i <= n; i++) {
        if(vis[i])continue;
        queue<pii> bfs; bfs.push({i, 1}); // 1 adya 0 inci
        while(!bfs.empty()){
            auto [c, p] = bfs.front(); bfs.pop();
            for(auto &e:adj[c]){
                if(vis[e])continue;
                vis[e] = 1;
                if(p)adjAns[c].push_back(e);
                else adjAns[e].push_back(c);
                bfs.push({e, !p});
            }
        }
    }
    int ans = 0;
    set<int> inci; for(int e: views::iota(1, n+1))inci.insert(e);
    for (int i = 1; i < n+1; i++) {
        if(adjAns[i].empty())ans++;
        for(auto &e:adjAns[i])inci.erase(e);
    }
    DEBUG(inci.size());
    DEBUG(ans);
    vis.assign(n+1, 0);
    adjAns.clear();
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


