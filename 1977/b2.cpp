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
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int indx;  
    ll x, val=0;cin>>x;
    // DEBUG(t);
    // DEBUG(x);
    vec<string> ans(32, "0");
    for(int i = 0; i<32; ++i){
        if(TEST(x, i))ans[i] = "1";
    }
    bool replacing = false;
    for(int i =0; i<31; ++i){
        if(!replacing && (ans[i]=="1") && (ans[i+1]=="1")){
            ans[i] = "-1";
            replacing = true;
        }
        else if(replacing){
            if(ans[i]=="1")ans[i]="0";
            else{
                ans[i] = "1";
                replacing=false;
                i--;
            }
        }
    }

    cout<<(32)<<'\n';
    for(int i = 0; i<32; ++i)cout<<ans[i]<<" ";
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
  