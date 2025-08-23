#include <bits/stdc++.h>
#include <locale>
#include <numeric>
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
    vec<pair<ll, ll>> inp(n);
    ll i, d;
    for(auto &e:inp){
        cin>>i>>d;
        e.first = i; e.second = d;
    }

    auto cnt = [inp](ll x){
        ll count = 0;
        for(auto &[l, r]:inp){
            if(l<=x)count+=min(x-l+1LL, r-l+1LL);
        }
        return count;
    };

    ll l = -2e9-1LL;
    ll r = 2e9+1LL;
    // k--;
    while(l+1LL < r){
        ll mid = (l+r)/2LL;
        // DEBUG(mid);
        if(cnt(mid)<=k)l = mid;
        else r = mid;
    }

    cout<<l+1LL<<endl;

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


