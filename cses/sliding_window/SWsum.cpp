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
    int n, k; cin>>n>>k;
    ll x, a, b, c; cin>>x>>a>>b>>c;
    ll left = x;
    ll right = x;
    ll cursum = x;
    ll ans = 0;
    for (int i = 1; i < k; i++) {
        right = (a*right + b)%c;
        cursum+=right;
    }
    ans ^= cursum;
    for (int i = k; i < n; i++) {
        right = (a*right + b)%c;

        cursum += right;
        cursum -= left;

        ans ^= cursum;

        left = (a*left + b)%c;
    }
    cout<<ans<<endl;
    
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


