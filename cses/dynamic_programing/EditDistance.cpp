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
    string s, m; cin>>s>>m;
    vec<vec<ll>> dp(s.size()+1, vec<ll>(m.size()+1, 1e7));
    // dp[i][j] min edit distance between s[0, i] & m[0, j]
    for (int i = 0; i < s.size()+1; i++) {
        dp[i][0] = i;
    }
    for (int j = 0; j < m.size()+1; j++) {
        dp[0][j] = j;
    }

    for (int i = 1; i < s.size()+1; i++) {
        for (int j = 1; j < m.size()+1; j++) {
            ll eq = (s[i-1] == m[j-1] ? dp[i-1][j-1]: dp[i-1][j-1]+1); //if eq no operation else replace
            ll ss = 1 + dp[i-1][j]; // skip in s
            ll sm = 1 + dp[i][j-1]; // skip in m
            dp[i][j] = min({eq, ss, sm});
        }
    }
    cout<<dp[s.size()][m.size()]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


