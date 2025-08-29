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
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int a, b, c, d; cin>>a>>b>>c>>d;
    int minh1 = min(a, b);
    int maxh1 = max(a, b);
    c-=a;
    d-=b;
    int minh2 = min(c, d);
    int maxh2 = max(c, d);
    if((maxh1 > (2*minh1 + 2)) || (maxh2 > (2*minh2 + 2))){
            cout<<"NO"<<endl;
            return;
            }
    cout<<"YES"<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


