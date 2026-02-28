#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<vec<int>> adj(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; 
        cin>>u>>v; u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> bfs;
    vec<bool> vis(n);

    bfs.push(0);
    vis[0] = 1;
    int ans = 0;
    int inlvl = 0;
    int prevlvl = 1;

    while(!bfs.empty()){
        int curr = bfs.front();
        bfs.pop();
        int adjg = 0;
        prevlvl--;
        for(int c:adj[curr]){
            if(!vis[c]){
                adjg++;
                bfs.push(c);
                vis[c] = 1;
            }
        }
        inlvl+=adjg;
        if(!prevlvl){
            prevlvl = inlvl;
            ans = max(ans, inlvl);
            inlvl = 0;
        }
        ans = max(ans, adjg+1);
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


