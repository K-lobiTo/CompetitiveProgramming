#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 998244353;
int t=1;
  
const int N = 55;
vec<ll> fact(N, 1);

ll mul(ll x, ll y){
    return (x * y)%MOD;
}

void fillFact(){
    for (ll i = 1; i < N; i++) {
        fact[i] = mul(i , fact[i-1]);
    }
}


ll binpow(ll x, ll y){
    ll z = 1;
    while( y > 0){
        if(y&1)z = mul(z, x);
        x = mul(x, x);
        y>>=1;
    }
    return z;
}

void solve(){
    int n; cin>>n;
    vec<ll> a(n+1); rAuto(a);
    ll s = accumulate(ALL(a), 0LL);
    ll maxi = *max_element(ALL(a));
    ll k = s/n;
    ll z = 0, bad = 0;
    for (int i = 1; i < n+1; i++) {
        ll x = min(a[i], k);
        a[i]-=x;
        a[0]-=k-x;
        z += (!a[i]);
        bad |= a[i] > 1 || a[0] < 0;
    }
    bad |= a[0] > z;
    if(bad)return void(cout<<0<<endl);

    ll ans = fact[z];

    ans = mul(ans, fact[n-(z-a[0])]);
    ans = mul(ans, binpow(fact[a[0]], MOD - 2LL));

    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    fillFact();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


