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
    int n, m; cin>>n>>m;
    vec<ll> x(n); rAuto(x);
    vec<vec<ll>> dp(n+1, vec<ll>(m+1));
    if(x[0])dp[0][x[0]] = 1;
    else{
        for (int i = 1; i < m+1; i++) {
            dp[0][i] = 1;
        }
    }
    auto ok = [&](ll v){return v>0 && v<=m;}; 
    for (int i = 1; i < n; i++) {
        if(x[i]){
            for (int d = -1; d < 2; d++) {
                if(ok(x[i]+d)){
                    dp[i][x[i]]+=dp[i-1][x[i]+d];
                    dp[i][x[i]]%=MOD;
                }
            }
        }
        else{
            for (int v = 1; v < m+1; v++) {
                for (int d = -1; d < 2; d++) {
                    if(ok(v+d)){
                        dp[i][v]+=dp[i-1][v+d];
                        dp[i][v]%=MOD;
                    }
                }
            }
        }
    }
    // for (int i = 0; i < n+1; i++) {
    //     cout<<i<<" : ";
    //     for (int j = 0; j < m+1; j++) {
    //         cout<<dp[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
    ll ans = 0;
    if(!x[n-1]){
        for (int i = 1; i < m+1; i++) {
            ans+=dp[n-1][i];
            ans%=MOD;
        }
    }
    else ans = dp[n-1][x[n-1]];
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


