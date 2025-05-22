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
    int n; 
    cin>>n;
    vec<vec<int>> ans(n,vec<int>(n, -1));
    queue<pair<int, int>> q;
    q.push({0, 0});
    ans[0][0] = 0;
    int di[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dj[] = {1, -1, 1, -1, 2, -2, 2, -2};

    while (!q.empty()) {
        auto [i, j] = q.front();
        q.pop();
        for (int r = 0; r < 8; r++) {
            int ni = di[r]+i;
            int nj = dj[r]+j;
            if(ni>=0 && ni<n && nj>=0 && nj<n && ans[ni][nj]==-1){
                ans[ni][nj] = ans[i][j] + 1;
                q.push({ni, nj});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


