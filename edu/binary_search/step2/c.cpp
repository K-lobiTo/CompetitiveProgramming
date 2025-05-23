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
ll n, x, y;  

bool ok(ll v){
    ll cant = min(x, y)<=v;
    if(cant)v-=min(x, y);
    else return 0;
    cant += (v/x)+(v/y);
    return cant>=n;

}

void solve(){
    cin>>n>>x>>y;
    ll l = 0; 
    ll r = 1;
    while (!(ok(r)))r*=2;
    // DEBUG(ok(3));
    while (l+1 < r) {
        ll m = (l+r)/2;
        if(ok(m))r = m;
        else l = m;
    }
    cout<<r<<endl;
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


