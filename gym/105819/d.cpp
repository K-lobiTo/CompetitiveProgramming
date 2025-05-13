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
    bool united(int i, int j) {
        return Find(i) == Find(j);
    }
};

int n, m; 
bool dfs(int node, int target, vec<bool> & vis, vec<vec<int>> &mat) {
    if(vis[node])return false;
    vis[node] = true;
    if(node==target)return true;
    for(int c = 0; c<n; ++c){
        if(dfs(mat[node][c], target, vis, mat)) return true;
    }
    return false;

}

  
void solve(){
    cin>>n>>m;
    int u, v;
    vec<int> a(n+1);
    for(int i = 0; i<n; ++i){
       cin>>a[i+1];  
    } 
    UnionFind ufg;
    ufg.init(n+1);
    for(int i = 0; i<m; ++i){
       cin>>u>>v; 
       ufg.Union(u, v);
    } 
    vec<vec<int>> ans(n, vec<int>(n));
    for(int j = 0; j<30; ++j){
        vec<vec<int>> mat(n, vec<int>(n, 0));
        // UnionFind uf;
        // uf.init(n+1);
        for(int m = 1; m<=n; ++m){
            if(TEST(a[m], j)){ // asubm have j bit set
                for(int i = 1; i<=n; ++i){
                    if(TEST(a[i], j)){ // asubi too
                        mat[i-1][m-1] = 1;
                        mat[m-1][i-1] = 1;
                        // uf.Union(m, i);
                    }
                }
            }
        }
        for(int m = 1; m<=n; ++m){
                for(int i = 1; i<=n; ++i){
                    if((ufg.Find(m) == ufg.Find(i)) && TEST(a[i], j)){
                        vec<bool> vis(n, 0);
                        if(dfs(m-1, i-1, vis, mat)){
                            if(m==8 && i==2 || m==2 && i==8){
                                DEBUG(j);
                                DEBUG(m);
                                DEBUG(i);
                            }
                            ans[m-1][i-1] = 1;
                            ans[i-1][m-1] = 1;
                        }
                }
            }
        }
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
  