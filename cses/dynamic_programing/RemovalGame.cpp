#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<ll> x(n); rAuto(x);
    vec<vec<ll>> dp(n, vec<ll>(n));
    vec<ll> acum(n+1); partial_sum(ALL(x), acum.begin()+1);
    for (int i = 0; i < n; i++) {
        dp[i][i] = x[i];
    }

    for (int siz = 1; siz < n; siz++) {
        for (int i = 0; i+siz < n; i++) { 
           dp[i][i+siz] = acum[i+siz+1] - acum[i] - min(dp[i+1][i+siz], dp[i][i+siz-1]);
        }
    }
    cout<<dp[0][n-1]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    while(t--){
        solve();
    }
    return 0;
}


