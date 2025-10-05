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
    vector<int> xp;
    vector<int> offset;

    void init(int n) { 
        uf.resize(n); rk.assign(n, 0);
        xp.assign(n, 0);
        offset.assign(n, 0);
        for (int i = 0; i < n; i++) {
            uf[i] = i;
        }
    }
    
    UnionFind(int n) { init(n); }

    int Find(int i) { 
        if(uf[i] != i){
            int p = uf[i];
            uf[i] = Find(p);
            offset[i] += offset[p];
        }
        return uf[i]; 
    }
    bool United(int i, int j) { return Find(i) == Find(j); }
    
    bool Union(int i, int j) {
        i = Find(i); j = Find(j);
        if (i == j) return 0;
        if (rk[i] < rk[j]) swap(i, j);
        uf[j] = i;
        offset[j] = xp[j] - xp[i];
        if (rk[i] == rk[j]) rk[i]++;
        return 1;
    }
    void add(int i, int v){
        i = Find(i);
        xp[i] += v;
    }
    int get(int i){
        int root = Find(i);
        return xp[root] + offset[i];

    }
};
  
void solve(){
    int n, m; cin>>n>>m;
    string type;
    int a, b;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin>>type>>a; a--;
        if(type[0] == 'a'){
            cin>>b;
            uf.add(a, b);
        }
        else if(type[0] == 'j'){
            cin>>b; b--;
            uf.Union(a, b);
        }
        else{
            cout<<uf.get(a)<<endl;
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


