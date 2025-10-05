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
    vector<int> uf;
    vector<int> rk;
    vector<int> mins;
    vector<int> maxs;
    vector<int> size;
    void init(int n) { 
        uf.resize(n); rk.assign(n, 0);
        mins.resize(n);
        maxs.resize(n);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
            mins[i] = i+1;
            maxs[i] = i+1;
        }
        size.assign(n, 1);
    }
    
    UnionFind(int n) { init(n); }

    int Find(int i) { 
        if(uf[i] != i){
            uf[i] = Find(uf[i]);
        }
        return uf[i]; 
    }
    bool United(int i, int j) { return Find(i) == Find(j); }
    bool Union(int i, int j) {
        i = Find(i); j = Find(j);
        if (i == j) return 0;
        if (rk[i] < rk[j]) swap(i, j);
        uf[j] = i;
        mins[i] = min(mins[j], mins[i]);
        maxs[i] = max(maxs[j], maxs[i]);
        size[i]+=size[j];
        if (rk[i] == rk[j]) rk[i]++;
        return 1;
    }
    vec<int> get(int i){
        i = Find(i);
        return {mins[i], maxs[i], size[i]};
    }
};
  
void solve(){
    int n, m; cin>>n>>m;
    string type;
    int a, b;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin>>type>>a; a--;
        if(type[0] == 'u'){
            cin>>b; b--;
            uf.Union(a, b);
        }
        else{
            vec<int> subans = uf.get(a);
            for(auto &e:subans)cout<<e<<' ';
            cout<<endl;
        }
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


