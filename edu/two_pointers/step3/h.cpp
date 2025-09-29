#include <bits/stdc++.h>
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
    ll n, m, s, A, B;
    cin>>n>>m>>s>>A>>B;
    vec<ll> a(n);
    vec<ll> b(m);
    rAuto(a);
    rAuto(b);
    sort(rALL(a));
    sort(rALL(b));
    vec<ll> pA(n+1);
    vec<ll> pB(m+1);
    partial_sum(ALL(a), pA.begin()+1);
    partial_sum(ALL(b), pB.begin()+1);

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        ll cAweight = i*A;
        ll forB = s - cAweight;
        if(cAweight > s)break;
        int idxB = min(m, forB/B);
        ans = max(ans, pA[i] + pB[idxB]);
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


