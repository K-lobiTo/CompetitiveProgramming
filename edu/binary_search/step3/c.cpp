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
int n, k; 
vec<ll> cord;
bool ok(ll d){
    ll arranged = 1;
    ll prev = cord[0];
    for (int i = 1; i < n; i++) {
        if(cord[i] - prev >= d){
            arranged++;
            prev = cord[i];
        }
        if(arranged>=k)return true;
    }

    return false;
}
  
void solve(){
    cin>>n>>k;
    cord.resize(n);
    rAuto(cord);
    ll l = 0;
    ll r = 1; while(ok(r))r*=2;
    // DEBUG(r);
    while(l+1 < r){
        ll mid = (l+r)/2;
        if(ok(mid))l = mid;
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


