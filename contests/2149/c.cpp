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
    int n, k; cin>>n>>k;
    vec<int> a(n); rAuto(a);
    vec<int> vis(n+1, false);
    for (int i = 0; i < n; i++) {
        vis[a[i]] += 1;
    }
    ll ans = 0;
    for (int i = 0; i <= k; i++) {
        if(i==k){
            if(vis[k])ans+=vis[k];
        }
        else{
            if(!vis[i]){
                ans++;
                if(vis[k]>0)vis[k]--;
            }
        }
    }
    cout<<ans<<endl;
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


