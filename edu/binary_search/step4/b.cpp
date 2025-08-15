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
int n, m; 
vec<vec<int>> ady;
  
bool ok(int m){
    vec<int> dp(n, 0);
    // IDGI
    return true;
}

void solve(){
    cin>>n>>m; 
    ady.assign(n, vec<int>(n, 0)); 
    // junctions are going from lower to higher
    for (size_t i = 0; i < m; i++) {
        int a, b, c;
        cin>>a>>b>>c; 
        ady[a-1][b-1]=c;
    }
    
    

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


