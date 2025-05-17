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
  
void solve(){ // O(n) 
    int n; cin>>n;
    vec<ll> a(n); rAuto(a);
    vec<ll> lrdiffs(n+1);
    vec<ll> rldiffs(n+1);
    ll ans = (ll)10e19;
    for(int i = 1; i<n; i+=2){
        lrdiffs[i+1] = max(lrdiffs[i-1], a[i]-a[i-1]); 
        rldiffs[n-i-1] = max(rldiffs[n-i+1], a[n-i]- a[n-i-1]);
    }
    if(!(n&1)){
        cout<<lrdiffs[n]<<endl;return;
    }
    for(int i = 0; i<n; i+=2){
        if(i && i<(n-1) && ( a[i]+1 )==a[i+1] && a[i]==( a[i-1]+1 ))continue;
        ll subans = max(rldiffs[i+1], lrdiffs[i]);
        subans += !subans; // if(!subans)subans = 1; lol
        ans = min(ans, subans);
    }
    // Debugs
    // for(auto &e: lrdiffs)cout<<e<<' ';
    // cout<<endl;
    // for(auto &e: rldiffs)cout<<e<<' ';
    // cout<<endl;

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
  