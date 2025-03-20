

#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
int n;

ll doDP(int i, int j, ll actSum, vec<vec<ll>> &dp, vec<vec<bool>> &vis, vec<int> &a){
    if(vis[i][j])return dp[i][j];
    vis[i][j] = true;
    if(i == (n-1)){
        dp[i][j] = actSum+a[i]*j; 
        DEBUG(actSum);
        DEBUG(j);
        DEBUG(dp[i][j]);
        return dp[i][j];
    }

    ll total = (max(
        actSum+a[i] * j + doDP(i+1, j+1, 0, dp, vis, a),
        actSum+a[i] + doDP(i+1, j, actSum+a[i], dp, vis, a)
    ));
    return dp[i][j] = total;
}

void solve(){
    cin>>n;
    vec<int>a(n);
    for(auto&e:a)cin>>e;
    vec<vec<ll>> dp(n+1, vec<ll>(n+1));
    vec<vec<bool>> vis(n+1, vec<bool>(n+1, false));
    doDP(0, 1, 0, dp, vis, a);
    cout<<dp[0][1]<<'\n';
    for(auto&e:a)cout<<e<<' ';
    cout<<'\n';
    for(auto&e:dp){
        for(auto&c:e)cout<<c<<' ';
        cout<<'\n';
    }

    cout<<'\n';

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  