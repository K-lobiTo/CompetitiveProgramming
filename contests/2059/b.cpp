
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
    int n, k;cin>>n>>k;
    vec<ll> a(n);
    rAuto(a);
    if(n==k){
        int idx = 1;
        for(int i = 1;i<n;i+=2){
            if(a[i]!=idx){
                cout<<idx<<endl;
                return;
            }
            idx++;
        }
        cout<<n/2+1 <<endl;
        return;
    }
    for(int i = 1; i<(n-k+2); ++i){
        if(a[i]!=1){
            cout<<1<<endl;return;
        }
    }
    cout<<2<<endl;

}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  