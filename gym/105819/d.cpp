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
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

struct UnionFind{
    vector<int> uf;
    void init(int n){uf.assign(n, -1);}
    int Find(int i){return (uf[i]==-1)? i : uf[i] = Find(uf[i]);}
    bool Union(int i, int j){
        bool e = Find(i)==Find(j);
        if(!e) uf[Find(i)] = Find(j);
        return e;
    }
    bool United(int i, int j) {
        return Find(i) == Find(j);
    }
};

int n, m; 
void bfs(int node, vec<vec<int>> &mat, UnionFind &uf, vec<bool> &withJ, vec<bool> &vis) {
    queue<int> q;
    q.push(node); // initial node will always have j bit set

    while(!q.empty()){
        int v = q.front(); q.pop();
        vis[v] = true;
        for(int i = 0; i<n; ++i){
            if(mat[v][i] && !vis[i] && withJ[i]){
                uf.Union(v, i);
                q.push(i);
            }
        }
    }
}

  
void solve(){
    cin>>n>>m;
    int u, v;
    vec<int> a(n);
    for(int i = 0; i<n; ++i){
       cin>>a[i];  
    } 
    vec<vec<int>> mat(n, vec<int>(n, 0));
    for(int i = 0; i<m; ++i){
       cin>>u>>v; 
       mat[u-1][v-1] = 1;
       mat[v-1][u-1] = 1;
    } 
    vec<vec<int>> ans(n, vec<int>(n));
    for(int j = 0; j<30; ++j){
        vec<bool> withJ(n);
        UnionFind uf;
        uf.init(n);


        for(int k = 0; k<n; ++k){
            if(TEST(a[k], j))withJ[k] = 1;
        }
        vec<bool> vis(n);
        for(int k = 0; k<n; ++k){
            if(withJ[k] && !vis[k]){
                bfs(k, mat, uf, withJ, vis);
            }
        }
        for(int i = 0; i<n; ++i)
            for(int k = 0; k<n; ++k)
                if(uf.United(i, k))ans[i][k] = 1;
        
    }
    for(auto &row : ans){for(auto&e: row)cout<<e;cout<<endl;}
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
//    cin>>t;
   while(t--){
      solve();
   }return 0;
}
  