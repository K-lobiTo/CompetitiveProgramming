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
    ll n, k; cin>>n>>k;
    vec<ll> a(n);
    vec<ll> b(n);
    rAuto(a);
    rAuto(b);
    bool notb = true;
    bool invalid = false;
    ll sum = -1;
    ll ans = 0;
    ll mini = (1LL << 30);
    ll maxi = -1;
    for(int i = 0; i<n; ++i){
        if(b[i] != -1)notb = false;
        mini = min(mini, a[i]);
        maxi = max(maxi, a[i]);
        if((b[i]!=-1) && (sum == -1))sum = a[i] + b[i];
    }
    if(notb){
        cout<<abs(k+1- abs(maxi-mini))<<endl;
        return;
    }
    for(int i = 0; i<n; ++i){
        if(b[i]!=-1){
            if((a[i] + b[i])!=sum){
                cout<<"0\n";
                return;
            }
        }
        else {
            if(abs(sum-a[i])>k || a[i]>sum){
                cout<<"0\n";
                return;
            }
        }
    }
    cout<<1<<endl;

}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
   