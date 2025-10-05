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
    int a, b; cin>>a>>b;
    vec<vec<int>> dp(a+1, vec<int>(b+1));
    for (int i = 1; i < a+1; i++) {
        dp[i][1] = i-1; 
    }
    for (int m = 1; m < b+1; m++) {
        dp[1][m] = m-1;
    }
    for (int i = 2; i < a+1; i++) {
        for (int j = 2; j < b+1; j++) {
            if(i==j)continue;
            else if(i<j){
                dp[i][j] = dp[i][j-i]+1;
            }
            else{
                dp[i][j] = dp[i-j][j]+1;
            }
            for (int f = 2; f < i; f+=2) {
                dp[i][j] = min(dp[i][j], dp[i-f][j] + dp[f][j] +1);
            }
            for (int c = 2; c < j; c+=2) {
                dp[i][j] = min(dp[i][j], dp[i][j-c] + dp[i][c] +1);
            }
        }
    }
    cout<<dp[a][b]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


