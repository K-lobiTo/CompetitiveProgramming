#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m; cin>>n>>m;
    int a, b;
    vec<vec<int>> adj(n);
    for (int i = 0; i < m; i++) {
        cin>>a>>b; a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    vec<bool> vis(n);
    vec<int> parent(n, -1);
    queue<int> bfs;
    bfs.push(0);
    vis[0] = 1;
    while(!bfs.empty()){
        int c = bfs.front();
        bfs.pop();
        if(c == n-1){
            vec<int> route;
            while(c>=0){
                route.push_back(c+1);
                c = parent[c];
            }
            reverse(ALL(route));
            cout<<route.size()<<endl;
            for(auto &e:route)cout<<e<<' ';
            cout<<endl;
            return;
            
        }
        for(auto e:adj[c]){
            if(!vis[e]){
                vis[e] = 1;
                parent[e] = c;
                bfs.push(e);
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


