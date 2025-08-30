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
    int n; cin>>n;
    ll p; cin>>p;
    vec<ll> a(n); rAuto(a);
    ll ans, ans2 = 1, totloop=accumulate(ALL(a), 0LL);
    ll s = 0;
    ll l = 0;
    ll len = 1e9;
    s = (p-1LL)/totloop * totloop;
    for (int r = 0; r < n*2; r++) {
        s+=a[r%n];
        while(s>=p){
            if(( r-l + 1  )< len){
                len = r-l+1;
                ans2 = l+1;
            }
            s-=a[l%n];
            l++;
        }
    }
    ans = (p-1)/totloop * n + len;
    cout<<ans2<<" "<<ans<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


