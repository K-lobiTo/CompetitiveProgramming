
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
    int n, m, l, r; cin>>n>>m>>l>>r; 
    int diff = n-m;
    // DEBUG(diff/2);
    // DEBUG(l);
    // DEBUG(l);

    // l+=diff/2;
    // r-=diff/2;
    // if(diff%2) r--;

    r-=diff;
    if(r<0){
        diff = 0-r;
        r+=diff;
        l+=diff;
    }
    cout<<l<<' '<<r<<endl;

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  