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


struct UnionFind {
    vec<int> uf;
    vec<int> rk;
    vec<vec<int>> elms;
    void init(int n) { 
        elms.assign(n, {});
        uf.resize(n);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
            elms[i].push_back(i);
        }; 
        rk.assign(n, 0);
    }
    UnionFind(int n) { init(n); }
    int Find(int i) { 
        return(uf[i] == i ? i : uf[i] = Find(uf[i]));
    }
    bool United(int i, int j) { return Find(i) == Find(j); }
    bool Union(int i, int j) {
        i = Find(i); j = Find(j);
        if (i == j) return 0;
        if (rk[i] < rk[j]) swap(i, j);
        uf[j] = i;
        for(int e:elms[j])elms[i].push_back(e);
        elms[j].clear();
        if (rk[i] == rk[j]) rk[i]++;
        return 1;
    }

};
  
void solve(){
    int n, m; cin>>n>>m;
    vec<pair<int, int>> nds(n);
    vec<pair<int, int>> nedg(n);
    vec<pair<int, int>> cuts;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        nds[i].first = max(-1, a-1);
        nds[i].second = max(-1, b-1);
    }
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        cuts.emplace_back(a-1, b-1);
        if(b-1) nedg[a-1].second = 1;
        else nedg[a-1].first = 1;
    }

    UnionFind uf(n);
    vec<int> times(n, -1);
    for(int i = 0; i<n; i++){
        if(!nedg[i].first && nds[i].first != -1){
            uf.Union(i, nds[i].first);
        }
        if(!nedg[i].second && nds[i].second != -1){
            uf.Union(i, nds[i].second);
        }
    }
    for (int i = m - 1; i >= 0; i--) {
        auto &[node, rh] = cuts[i];
        int tonode = (rh ? nds[node].second : nds[node].first);
        if(tonode == -1) {DEBUG("-1 found"); continue;}
        bool nin = uf.United(node, 0), tnin = uf.United(tonode, 0);
        if(nin && !tnin){
            for(auto &e:uf.elms[uf.Find(tonode)]){
                times[e] = i;
            }
        }
        else if(!nin && tnin){
            for(auto &e:uf.elms[uf.Find(node)]){
                times[e] = i;
            }
        }
        uf.Union(node, tonode);
    }

    for (int i = 0; i < n; i++) {
        cout<<times[i]<<endl;
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


