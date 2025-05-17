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
    ll limitL = 1;
    ll limitU = 1;
    ll limitD = n;
    ll limitR = m;
    ll ans = 0;
    while(//((  limitD != limitU ) || (limitR!=limitL) ) &&
     (a!=limitD || a!=limitU) || (b!=limitL || b!=limitR)){
        ll dR = limitR-b;
        ll dL = b - limitL;
        ll dU = a - limitU;
        ll dD = limitD-a;
        ll dUD = max(dU, dD);
        ll dRL = max(dL, dR);
        if(dUD > dRL){
            if(dU>dD)limitU = a;
            else limitD = a;
        }
        else if(dUD < dRL){
            if(dR > dL)limitR = b;
            else limitL = b;
        }
        else {
            if(dUD){
                if(dU>dD)limitU = a;
                else limitD = a;
            }
            else {
                if(dR > dL)limitR = b;
                else limitL = b;
            }
        }
        b = limitL + (limitR-limitL)/2;
        a = limitU + (limitD-limitU)/2;
        // DEBUG(a);
        // DEBUG(b);

        ans++;

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
  