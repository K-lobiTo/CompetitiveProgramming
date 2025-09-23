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
    int n; cin>>n;
    vec<string> mat(n);
    rAuto(mat);
    vec<vec<ll>> dp(n, vec<ll>(n, 0));
    vec<vec<bool>> vis(n, vec<bool>(n));
    auto ok = [&](int i, int j) -> bool{
        return i<n && j<n && mat[i][j]!='*';
    };
    queue<pair<int, int>> q;
    if(ok(0, 0)){
        q.push({0, 0});
        dp[0][0] = 1;
        vis[0][0] = 1;
    }
    while(!q.empty()){
        auto &[x, y] = q.front();
        q.pop();
        if(ok(x+1, y)){
            dp[x+1][y]+=dp[x][y];
            dp[x+1][y]%=MOD;
            if(!vis[x+1][y]){
                q.push({x+1, y});
                vis[x+1][y]=1;
            }
        }
        if(ok(x, y+1)){
            dp[x][y+1]+=dp[x][y];
            dp[x][y+1]%=MOD;
            if(!vis[x][y+1]){
                q.push({x, y+1});
                vis[x][y+1]=1;
            };
        }
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < n; j++) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    cout<<dp[n-1][n-1]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


