#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<ll> p(n); rAuto(p);
    vec<ll> pref(p); 
    vec<ll> suf(p);
    for (int i = 1; i < n; i++) {
        pref[i] = gcd(pref[i], pref[i-1]);
        suf[n-i-1] = gcd(suf[n-i-1], suf[n-i]);
    }
    ll ans = 0;
    for (int i = 1; i < n-1; i++) {
        ans+=min(pref[i], suf[i]);
    }
    ans+=gcd(pref[n-1], suf[0]);
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    while(t--){
        solve();
    }
    return 0;
}


