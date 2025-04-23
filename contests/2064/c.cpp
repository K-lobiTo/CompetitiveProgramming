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
    int n; cin>>n;
    vec<ll> a(n);
    rAuto(a);
    vec<ll> psPos(n);
    vec<ll> psNeg(n);
    psPos[0] = max(0LL, a[0]);
    psNeg[n-1] = -min(a[n-1], 0LL);
    for(int i = 1; i<n; ++i){
        psPos[i] = psPos[i-1];
        if(a[i]>0)psPos[i]+=a[i];
    }
    for(int i = (n-2); i>=0; --i){
        psNeg[i] = psNeg[i+1];
        if(a[i]<0)psNeg[i]-=a[i];
    }
    ll maxi = -(1LL << 50);
    for(int i = 0; i<n; ++i){
        maxi = max(maxi, psPos[i]+psNeg[i]);
    }
    cout<<maxi<<endl;
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  