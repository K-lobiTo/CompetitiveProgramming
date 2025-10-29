#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
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
    vec<ll> a(2*n); rAuto(a); 
    vec<ll> ps(2*n + 1);
    vec<ll> ans(n);
    partial_sum(ALL(a), ps.begin() + 1);
    vec<ll> pseven(2*n + 1);
    vec<ll> psodd(2*n + 1);
    for (int i = 0; i < 2*n; i++) {
        pseven[i+1] = pseven[i] + (i&1) * a[i];
        psodd[i+1] = psodd[i] + (1^(i&1)) * a[i];
    }
    // for(auto &e:pseven)cout<<e<<' '; cout<<endl;
    // for(auto &e:psodd)cout<<e<<' '; cout<<endl;
    for (int i = 1; i <= n ; i++) {
        int keep = i-1;
        ll subans = ps[2*n]-ps[2*n-keep] - ps[keep];
        // if even sum evens sub odds and viceversa
        if(keep&1)subans += psodd[2*n-keep] - psodd[keep] - (pseven[2*n-keep] - pseven[keep]);
        else subans += pseven[2*n-keep] - pseven[keep] - (psodd[2*n-keep] - psodd[keep]);
        ans[keep] = subans;
    }

    for(auto &e:ans)cout<<e<< ' ';
    cout<<endl;
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


