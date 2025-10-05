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
    int n, m; cin>>n>>m;
    string type;
    int a, b;
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        cin>>type; 
        cin>>a>>b;
        if(type[0]=='g'){
            cout<<(uf.United(a-1, b-1) ? "YES": "NO")<<endl;
        }
        else{
            uf.Union(a-1, b-1);
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


