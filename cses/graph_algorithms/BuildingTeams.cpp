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
    vec<int> teams(n, -1);
    for (int i = 0; i < n; i++) {
        if(!vis[i]){
            teams[i] = 0;
            queue<int> bfs; 
            bfs.push(i); vis[i] = 1;
            while(!bfs.empty()){
                int c = bfs.front(); bfs.pop();
                for(auto &e:adj[c]){
                    if(teams[e] == teams[c])
                        return void(cout<<"IMPOSSIBLE"<<endl);
                    if(!vis[e]){
                        vis[e] = 1;
                        teams[e] = teams[c]^1;
                        bfs.push(e);
                    }
                }
            }
        }
    }
    for(auto &e:teams)cout<<e+1<<' ';
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


