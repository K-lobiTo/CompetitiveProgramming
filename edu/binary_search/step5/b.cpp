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
    ll n, k; cin>>n>>k;

    auto cnt = [n](ll x){
        ll ans = 0;
        for (ll i = 1; i <= n; i++) {
            ll l = 0;
            ll r = n+1; 
            while(l+1 < r){
                ll mid = (l+r)/2LL;
                if(i*mid < x)l=mid;
                else r=mid;
            }                
            ans+=l;
        }
        return ans;
    };        

    ll l = 1;
    ll r = n*n+1;
    while(l+1 < r){
        ll mid = (l+r)/2LL;
        if(cnt(mid) < k)l=mid;
        else r = mid;
    }
    cout<<l<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


