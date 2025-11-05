#include <bits/stdc++.h>
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
    ll guss = (n*(n+1))/2;
    ll gussmid = guss/2;
    if(guss&1)return void(cout<<0<<endl);
    vec<ll> dp(gussmid+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        // DEBUG(i);
        for (int sum = gussmid; sum-i >= 0; sum--) {
            dp[sum]+=dp[sum-i];
            dp[sum]%=MOD;
        }
        // for(auto &e:dp)cout<<e<<' ';
        // cout<<endl;
    }
    ll inv2 = (MOD + 1) / 2;
    ll ans = dp[gussmid] * inv2 % MOD;
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    while(t--){
        solve();
    }
    return 0;
}


