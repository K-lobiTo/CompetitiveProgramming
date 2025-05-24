#include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
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
ld c;

bool ok(ld x){
    return (x*x + sqrt(x))>=c;
}
  
void solve(){
    cin>>c;
    ld l = 0;
    ld r = 1; while (!ok(r))r*=2;
    for (size_t i = 0; i < 100; i++) {
        ld m = ( l+r )/2;
        if(ok(m))r = m;
        else l = m;
    }
    cout<<r<<endl;
    
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    cout<<setprecision(20);
    while(t--){
        solve();
    }
    return 0;
}


