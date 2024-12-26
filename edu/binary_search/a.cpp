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
  int n, k, top, bot = 0, m, ki; cin>>n>>k;
  int v[n];
  bool ans = false;
  for(int i = 0; i<n; ++i ){
    cin>>v[i];
  }
  
  while (k--){
    cin>>ki;
    top = n-1;
    bot = 0;
    ans = false;
    while(top>=bot){
        m = (top+bot)/2;
        if(v[m]==ki){
            ans = true;
            break;}
        else if(v[m]<ki){
            bot = m+1;
        }
        else{top = m-1;}
    }
    cout<<(ans? "YES\n" : "NO\n");
  }
  
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  