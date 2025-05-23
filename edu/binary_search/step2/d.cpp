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
ll m, n;
vec<vec<ll>> as;



ll fb(ll t, vec<ll> &a){
    return t/(a[0]*a[1] +a[2])*a[1] + min(a[1], t%(a[0]*a[1]+a[2])/a[0]);
}


bool ok(ll t){
    ll ballons = 0;
    for(auto &e:as){
        ballons+=fb(t, e);
    }
    return ballons>=m;
}

vec<ll> ans(ll t){
    ll sum = 0;
    vec<ll> ballons;
    for(auto &e:as){
        if(sum>=m){ballons.push_back(0); continue;}
        ll asballons = fb(t, e);
        if(sum+asballons > m)asballons = m-sum;
        ballons.push_back(asballons);
        sum+=ballons.back();
    }
    return ballons;
}

  
void solve(){
    cin>>m>>n;
    as.assign(n, vec<ll>(3));
    for(auto &e:as)rAuto(e);

    ll l = -1;
    ll r = 1; while(!ok(r))r*=2;

    while (l+1<r) {
        ll mid = (l+r)/2;
        if(ok(mid))r = mid;
        else l = mid;
    }
    cout<<r<<endl;
    for(auto &e:ans(r))cout<<e<<' ';
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


