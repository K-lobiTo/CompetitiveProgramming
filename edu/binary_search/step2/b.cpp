#include <bits/stdc++.h>
#include <cmath>
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
#define ld long double
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
ld n, k;
ld err = 1e-7;

bool ok(vec<ld> &a, ld size){
    ll ans = 0;
    for(auto &e:a)ans+=floor(e/size);
    return ans>=k;
}

  
void solve(){
    cin>>n>>k;
    vec<ld> a(n);
    rAuto(a);
    ld l = 0;
    ld r = 1;
    while (ok(a,r))r*=2;
    // DEBUG(r);
    while (l+err < r) {
        ld m = (l+r)/2.0;
        if(ok(a, m))l = m;
        else r = m;
    }
    cout<<setprecision(20)<<l<<endl;
    
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


