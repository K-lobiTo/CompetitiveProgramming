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
    vec<string> mat(n);
    rAuto(mat);
    vec<vec<bool>> dp(n, vec<bool>(n));
    if(n==1)return void(cout<<mat[0]<<endl);
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[0][1] = 1;
    string ans = "";
    ans+=mat[0][0];
    for (int dist = 1; dist < 2*n-1; dist++) {
        char minchar = 'Z';
        for (int i = max(0, dist - (n-1)); i <= min(n-1, dist); i++) {
            int j = dist-i;
            if(j<0 || j>=n)continue;
            if(dp[i][j]){
                minchar = min(minchar, mat[i][j]);
            }
        }
        for (int i = max(0, dist - (n-1)); i <= min(n-1, dist); i++) {
            int j = dist-i;
            if(j<0 || j>=n)continue;
            if(dp[i][j] && mat[i][j] == minchar){
                if(i!=n-1)dp[i+1][j] = 1;
                if(j!=n-1)dp[i][j+1] = 1;
            }
        }
        ans+=minchar;
    }
    // for(auto &f:dp){
    //     for(auto c:f)cout<<c<<' ';
    //     cout<<endl;
    // }

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

