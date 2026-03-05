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
const int MAX = 1e6, MOD = 1e9+7;
int t=1;
vec<vec<ll>> dp(MAX+1, vec<ll>(2));

void solve(){
    dp[1][0] = 1;
    dp[1][1] = 1;
    for (int i = 2; i < MAX+1; i++) {
        dp[i][0] = (2*dp[i-1][0] + dp[i-1][1])%MOD;
        dp[i][1] = (4*dp[i-1][1] + dp[i-1][0])%MOD;
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin>>t;
    solve();
    while(t--){
        int n; cin>>n;
        cout<<(dp[n][0] + dp[n][1])%MOD<<endl;
    }
    return 0;
}


