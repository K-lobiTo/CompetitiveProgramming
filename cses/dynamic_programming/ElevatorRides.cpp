#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define pii pair<int,int>

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, x; cin>>n>>x;
    vec<int> w(n); for(auto &e:w)cin>>e;
    vec<pii> dp(1<<n, {1e9, 1e9});
    dp[0] = {1, 0};
    for (int msk = 1; msk < (1<<n); msk++) {
        for (int b = 0; b < n; b++) {
            if(msk&(1<<b)){
                int comp = msk^(1<<b);
                int nw = dp[comp].second + w[b]; 
                bool nride = 0;
                if(nw>x){
                    nw = w[b];
                    nride = 1;
                }
                pii curr = {dp[comp].first + nride, nw};
                dp[msk] = min(dp[msk], curr);
            }
        }
    }
    // for(auto &e:dp)cout<<e.first<<" "<<e.second<<endl;
    cout<<dp[( 1<<n ) - 1].first<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


