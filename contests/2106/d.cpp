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
    ll n, m; cin>>n>>m; 
    vec<ll> a(n);
    vec<ll> b(m);
    rAuto(a);
    rAuto(b);
    ll j = 0; 
    int k = 0;
    ll minimk = (1LL<<30);
    for(int i = 0; i<n && j<m; ++i){
        if(b[j]<a[i]){
            k++;
            minimk = min(b[j], minimk);
        }
        else j++;
    }
    if(!k){
        cout<<0<<endl;
        return;
    }
    if(j<(m-2)){
        cout<<-1<<endl;
        return;
    }


    


}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  