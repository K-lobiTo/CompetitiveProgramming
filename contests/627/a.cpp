#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define ull unsigned long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll s, x; cin>>s>>x;
    ll df  = s-x;
    ll carry = df/2;
    if(df&1 || df<0 || carry&x)return void(cout<<0<<endl);
    ll ans = 1ULL<<popcount((ull)x);
    if(s==x)ans-=2;
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


