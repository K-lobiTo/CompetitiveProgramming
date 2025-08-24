#include <algorithm>
#include <bits/stdc++.h>
#include <iterator>
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
    ll n, k; cin>>n>>k;
    vec<ll> a(n);
    vec<ll> b(n);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;
    sort(ALL(a));
    sort(ALL(b));

    auto ok = [a, b, k](ll x){ // x is the limit element
        ll ans = 0;
        for(auto &e:b){
            if(e+a[0] > x)break; // no more elements could follow the condition
            ans += distance(a.begin(), lower_bound(ALL(a),  x-e));
        }
        return ans<k;
    };


    // ok(x) is true the amount of sums <= x is less than k 

    ll l = 0;
    ll r = 2e9+1LL; // max possible sum
    while(l+1 < r){
        ll mid = (l+r)/2LL;
        if(ok(mid)) l = mid;
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


