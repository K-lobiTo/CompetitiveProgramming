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

    // return x < (n-c + b-1)/b;
  
void solve(){
    ll n, b, c;
    cin>>n>>b>>c;
    if(c>=n) return void(cout<<n<<endl);
    if(!b){
        ll ans;
        if(n-2 <= c) ans = n-1;
        else ans = -1;
        return void(cout<<ans<<endl);
    }
    ll x = (n-c-1)/b;

    cout<<n-max(0LL, x+1LL)<<endl;
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


