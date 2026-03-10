#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, k; cin>>n>>k;
    vec<ll> a(n), b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;
    k&=1;
    vec<int> accL(n), accR(n);
    for (int i = 0; i < n; i++) {
        accL[i] = (i && accL[i-1] > 0 ? accL[i-1] : 0LL) + a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        accR[i] = (i+1 < n && accR[i+1] > 0 ? accR[i+1] : 0LL) + a[i];
    }
    if(!k)return void(cout<<*ranges::max_element(accR)<<endl);
    ll ans = LONG_MIN;
    for (int i = 0; i < n; i++) {
        ans = max(ans, accL[i] + accR[i] - a[i] + b[i]);
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


