#include <bits/stdc++.h>
#include <cstdlib>
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
    vec<ll> a(n);
    vec<ll> b(m);
    rAuto(a);
    rAuto(b);
    vec<vec<int>> dp(n+1, vec<int>(m+1)); 

    for (int i = 1; i < n+1; i++) {
        int c = a[i-1];
        for (int j = 1; j < m+1; j++) {
            if(b[j-1] == c){
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else {
                dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
    }
    int len = dp[n][m];
    vec<ll> lcs(len);
    int i = n, j = m, idx = len - 1;
    
    while (i > 0 && j > 0) {
        if (a[i - 1] == b[j - 1]) {
            lcs[idx] = a[i - 1];
            i--;
            j--;
            idx--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }
    cout<<len<<endl;
    for(auto &e:lcs)cout<<e<<' ';
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


