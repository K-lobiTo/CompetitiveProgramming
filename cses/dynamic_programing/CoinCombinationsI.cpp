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
    int n, x; cin>>n>>x;
    vec<ll> c(n); rAuto(c);
    sort(ALL(c));
    vec<ll> dp(x+c[n-1]+1, 0);
    dp[0] = 1;
    bool f=1;
    for (int i = 0; i < x+1 && f; i++) {
        if(dp[i] == 1e9)continue;
        for (int j = 0; j < n && f; j++) {
            if(i+c[j] > x+c[n-1])f = 0;
            else{
                dp[i+c[j]] += dp[i]; 
                dp[i+c[j]]%=MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


