#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll unsigned long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

// ll upperPot2(int n){
//     for(int i = 0; i<n ;++i){
//         if((1<<i)>=n)return 1<<i;
//     }
// }

void solve(){
    int indx;  
    ll x, val;cin>>x;
    // DEBUG(t);
    // DEBUG(x);
    vec<string> ans(32, "0");
    for(int i = 0; i<32 ;++i){
        if((1<<i)>=x){
            val = 1<<i;
            indx = i;
            ans[i]="1";
            break;
        }
    }
    for(int i = indx; i>=0; --i){
        if((val-(1<<i))>=x){
            val-=(1<<i);
            ans[i]="-1";
        }
    }
    for(int i = 0;i<(indx-1); ++i){
        if((ans[i]=="-1") && (ans[i+1]=="-1")){
            ans[i]="1";
            ans.erase(ans.begin()+(i+1));
            indx--;
        }
    }

    cout<<(indx+1)<<'\n';
    for(int i = 0; i<=indx; ++i)cout<<ans[i]<<" ";
    cout<<'\n';


}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  