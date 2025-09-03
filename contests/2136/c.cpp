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
    vec<int> a(n); rAuto(a);
    vec<deque<int>> dq(n+1);
    vec<ll> dp(n+1); dp[0] = 0;
    for (int i = 1; i < n+1; i++) {
        dp[i] = dp[i-1];
        dq[a[i-1]].emplace_back(i);
        if(dq[a[i-1]].size() > a[i-1])dq[a[i-1]].pop_front();
        if(dq[a[i-1]].size() == a[i-1])dp[i] = max(dp[i], dp[dq[a[i-1]].front()-1] + a[i-1]);  
    }
    cout<<dp[n]<<endl;
    
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
