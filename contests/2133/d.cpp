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
  
void solve(){
    int n; cin>>n;
    vec<ll> h(n); rAuto(h);
    vec<ll> dpd(n);
    vec<ll> dpu(n);
    dpd[n-1] = h[n-1];
    dpu[n-1] = h[n-1];
    for (ll i = n - 2; i >= 0; i--) {
        dpd[i] = h[i] + min(dpd[i+1]-1, dpu[i+1]);
        dpu[i] = h[i] + min(dpd[i+1]-min((i+1LL),h[i+1]), dpu[i+1]); 
    }
    cout<<dpd[0]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


