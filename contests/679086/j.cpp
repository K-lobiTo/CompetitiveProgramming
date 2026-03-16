#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

struct UnionFind {
    vector<int> uf;
    vector<int> rk;
    void init(int n) { uf.assign(n, -1); rk.assign(n, 0); }
    UnionFind(int n) { init(n); }
    int Find(int i) { return (uf[i] == -1) ? i : uf[i] = Find(uf[i]); }
    bool United(int i, int j) { return Find(i) == Find(j); }
    bool Union(int i, int j) {
        i = Find(i); j = Find(j);
        if (i == j) return 0;
        if (rk[i] < rk[j]) swap(i, j);
        uf[j] = i;
        if (rk[i] == rk[j]) rk[i]++;
        return 1;
    }
};
  
void solve(){
    int n, m1, m2; cin>>n>>m1>>m2;
    vec<set<int>> adjF(n+1);
    vec<set<int>> adjG(n+1);

    UnionFind ufF(n+1);
    for (int i = 0; i < m1; i++) {
        int u, v; cin>>u>>v;
        adjF[u].insert(v);
        adjF[v].insert(u);
        ufF.Union(u, v);
    }

    UnionFind ufG(n+1);
    for (int i = 0; i < m2; i++) {
        int u, v; cin>>u>>v;
        adjG[u].insert(v);
        adjG[v].insert(u);
        ufG.Union(u, v);
    }

    ll ans = 0;
    auto mf = [](int a, int b) -> pair<int, int> {
        if(a<b)return {a, b};
        return {b, a};
    };
    set<pair<int, int>> consd;
    for (int i = 1; i < n+1; i++) {
        for(auto &e:adjF[i]){
            if(!ufG.United(i, e) && !consd.contains(mf(i, e))){
                consd.insert(mf(i, e));
                ans++;
            }
        }
    }

    for (int i = 1; i < n+1; i++) {
        for(auto &e:adjG[i]){
            if(!ufF.United(i, e)){
                ufF.Union(i, e);
                ans++;
            }
        }
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


