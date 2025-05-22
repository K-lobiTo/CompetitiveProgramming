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
  
void solve(){
    ll n, m, a, b;cin>>n>>m>>a>>b;
    auto subans = [&](int i, int j){
        ll sans = 1;
        while (i!=1) {
            sans++;
            i = (i+1)/2;
        }
        while (j!=1) {
            sans++;
            j = (j+1)/2;
        }
        return sans;
    };
    ll ans = (ll)(1e9) + 1LL;
    ans = min(ans, subans(n, m-b+1));
    ans = min(ans, subans(n-a+1,m));
    ans = min(ans, subans(a, m));
    ans = min(ans, subans(n, b));

    cout<<ans<<endl;
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  
