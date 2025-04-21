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
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
bool solve(){
    ll n, m;cin>>n>>m;
    vec<ll> a(n);
    vec<ll> b(m);
    rAuto(a);
    rAuto(b);
    sort(ALL(b));
    if(a[0]>(b[0]-a[0]))a[0] = b[0]-a[0];
    for(int i = 1; i<n; ++i){
        auto lb = lower_bound(ALL(b), a[i]+a[i-1]);
        if(lb!=b.end()){
            ll bsubj = *lb;
            if(a[i]>(bsubj-a[i]) || (a[i]<a[i-1]))a[i] = bsubj-a[i];
        }
        if(a[i]<a[i-1])return false;
    }
    return true;
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
    cout<<(solve()? "YES\n" : "NO\n");
   }return 0;
}
  