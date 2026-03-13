#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7, MXN = 5e3+5;
int t=1;

vec<vec<int>> g(MXN, vec<int>(MXN));

void fillG(){
    for (int i = 0; i < MXN; i++) {
        g[0][i] = g[i][0] = g[i][i] = i;
    }
    for (int i = 1; i < MXN; i++) {
        for (int j = 1; j < i; j++) {
            g[i][j] = g[j][i] = g[j][i%j];
        }
    }
}
  
void solve(){
    int n; cin>>n;
    int k = 0, mx = 0;
    vec<int> a(n);
    for(auto &e:a){
        cin>>e;
        k = g[k][e];
    }
    for(auto &e:a)e/=k, mx = max(mx, e);
    vec<int> dp(mx+1, 1e9);
    for(auto &e:a)dp[e] = 0;
    for (int i = mx; i >= 1; i--) {
        for(auto &e:a){
            dp[g[i][e]] = min(dp[g[i][e]], dp[i] + 1);
        }
    }
    int ans = max(dp[1]-1, 0);
    for(auto &e:a)if(e>1)ans++;
    cout<<ans<<endl;
    
    
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 
    fillG();

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


