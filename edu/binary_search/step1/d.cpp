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
    int n, k;cin>>n;
    vec<ll> a(n); 
    rAuto(a);
    cin>>k;
    sort(ALL(a));
    ll l, r, d, u;
    while (k--) {
        cin>>l>>r;
        d = -1;
        u = n;
        while (d+1<u) {
            ll m = (u+d)/2;
            if(a[m]<l)d = m;
            else u = m;
        }
        ll ans = u;
        d = -1;
        u = n;
        while (d+1<u) {
            ll m = (u+d)/2;
            if(a[m]<=r)d = m;
            else u = m;
        }
        ans = d-ans+1;
        cout<<ans<<' ';
    }
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


