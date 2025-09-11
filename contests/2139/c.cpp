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
    ll k, x; cin>>k>>x;
    ll y = (1LL<<(k+1)) - x;
    vec<int> ops;

    while(x!=1LL<<k){
        if(x<y){
            ops.push_back(1);
            y-=x;
            x*=2;
        }
        else {
            ops.push_back(2);
            x-=y;
            y*=2;
        }
    }
    cout<<ops.size()<<endl;
    for (int i = ops.size() - 1; i >= 0; i--) {
        cout<<ops[i]<<' ';
    }
    cout<<endl;
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


