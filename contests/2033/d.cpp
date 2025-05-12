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
    int n;
    cin>>n;
    vec<ll> a(n); rAuto(a);
    vec<ll> b(ALL(a)); 
    set<ll> exist;
    ll ans = 0;
    ll real = 0;
    partial_sum(ALL(a), a.begin());
    for(int i = 0; i<n; ++i){
        if((!(a[i]+real) || !b[i]) || exist.find(a[i])!=exist.end()){
            ans++;
            real = -a[i];
            exist.clear();
        }
        else exist.insert(a[i]);
    }
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
  