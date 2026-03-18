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
    UnionFind(int n) { uf.resize(n); ranges::iota(uf, 0); rk.assign(n, 0); }
    int Find(int i) { return (uf[i] == i) ? i : uf[i] = Find(uf[i]); }
    bool United(int i, int j) { return Find(i) == Find(j); }
    bool Union(int i, int j) {
        i = Find(i); j = Find(j);
        if (i == j) return 0;
        if (rk[i] < rk[j]) swap(i, j);
        uf[j] = i;
        if (rk[i] == rk[j]) rk[i]++;
        return 1;
    }

    int cComp(int s, int f){
        set<int> dif;
        for (int i = s; i <= f; i++) {
            dif.insert(Find(i));
        }
        return dif.size();
    }
};
  
void solve(){
    int n, m1, m2; cin>>n>>m1>>m2;
    vec<pair<int, int>> adjF(m1);

    UnionFind ufF(n+1);
    UnionFind ufG(n+1);

    for(auto &[u, v]:adjF)cin>>u>>v;

    for (int i = 0; i < m2; i++) {
        int u, v; cin>>u>>v;
        ufG.Union(u, v);
    }

    auto lf = [] (int a, int b) -> pair<int, int> {
        if(a<b) return {a, b};
        return {b, a};
    };

    ll ans = 0;
    for(auto &[u, v]:adjF){
        if(!ufG.United(u, v))
            ans++;
        else 
            ufF.Union(u, v);
    }

    int cF = ufF.cComp(1, n);
    int cG = ufG.cComp(1, n);

    ans += cF - cG;
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


