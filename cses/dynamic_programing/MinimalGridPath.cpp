#include <bits/stdc++.h>
#include <numeric>
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
    vec<vec<pair<int, int>>> parent(n, vec<pair<int, int>>(n, {-1, -1}));
    vec<vec<ll>> dp(n, vec<ll>(n));
    vec<string> matorig = mat;
    dp[0][0] = mat[0][0];
    for (int i = 1; i < n; i++) {
        mat[i][0] = max(mat[i-1][0], mat[i][0]);
        mat[0][i] = max(mat[0][i-1], mat[0][i]);
        dp[i][0] += dp[i-1][0] + mat[i][0];
        dp[0][i] += dp[0][i-1] + mat[0][i];
        parent[i][0] = {i-1, 0};
        parent[0][i] = {0, i-1};
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            // dp[i][j] = mat[i][j];
            char maxftop = max(mat[i][j], mat[i-1][j]);
            char maxflft = max(mat[i][j], mat[i][j-1]);
            if(mat[i-1][j] == mat[i][j-1]){
                dp[i][j] += max(maxftop, maxflft);
                mat[i][j] = max(maxftop, maxflft);
                if(dp[i-1][j] < dp[i][j-1]){
                    dp[i][j] += dp[i-1][j];
                    parent[i][j] = {i-1, j};
                }
                else{
                    dp[i][j] += dp[i][j-1];
                    parent[i][j] = {i, j-1};
                }
            }
            else if(mat[i-1][j] < mat[i][j-1]){
                dp[i][j] += dp[i-1][j] + maxftop;
                mat[i][j] = maxftop;
                parent[i][j] = {i-1, j};
            }
            else {
                dp[i][j] += dp[i][j-1] + maxflft;
                mat[i][j] = maxflft;
                parent[i][j] = {i, j-1};
            }
        }
    }
    // for(auto &e:mat){
    //     for(auto &c:e){
    //         cout<<c;
    //     }
    //     cout<<endl;
    // }
    // cout<<endl;
    // for(auto &e:dp){
    //     for(auto &c:e){
    //         cout<<c<<' ';
    //     }
    //     cout<<endl;
    // }
        
    string ans = "";
    ans+=matorig[n-1][n-1];
    auto [x, y] = parent[n-1][n-1];
    while(x!=-1 || y!=-1){
        ans+=matorig[x][y];
        int xx = x;
        x = parent[x][y].first;
        y = parent[xx][y].second;
    }
    reverse(ALL(ans));
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


