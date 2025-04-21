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
    int n;cin>>n;
    ll k;cin>>k;
    vec<ll> a(n);
    rAuto(a);
    int count = 0;
    for(int i = 0; i<n; ++i){
        if(a[i]<=k)count++;
    }
    if(n==3 && count)return true;
    // for(auto &e: a)cout<<e<<' ';
    // cout<<endl;
    if(count && ((a[0]<=k)||(a[1]<=k)))return true;
    if(count<2)return false;
    count = 0;
    int r = (n-1)-1;
    // DEBUG(r);
    for(int i = (n-1); i>=r && i>0; --i){
        // DEBUG(i);
        // DEBUG(r);
        if(a[i]<=k){
            count++;
            r-=2;
        }
    }
    if(count<2)return false;
    return true;


}

  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      cout<<(solve()? "YES\n": "NO\n");
   }return 0;
}
  