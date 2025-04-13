
#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll n, l; cin>>n>>l;
    vec<ll> a(n);
    ll diam = -1;
    for(auto &e:a)cin>>e;
    sort(ALL(a));
    // DEBUG(a[0]);
    diam = a[0]*2; //4
    // DEBUG(diam);
    for(ll i = 0; i<(n-1); ++i){
        diam = max(diam, a[i+1]-a[i]);
    }
    diam = max(diam, (l-a[n-1])*2);
    // DEBUG(diam);
    double radious = (diam+0.0)/2;
    cout<<setprecision(10)<<radious<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  