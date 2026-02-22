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

ll ans(ll n, ll k) {
    if(n / 2 >= k) {
        return 2 * k;
    }
    if((n & 1) && (n + 1) / 2  == k) {
        return 1;
    }
    if(n & 1) {
        return 2 * ans(n / 2, k - n / 2 - 1) + 1;
    }
    return 2 * ans(n / 2, k - n / 2) - 1;

}
  
void solve(){
    ll k, n; cin>>n>>k;
    cout << ans(n, k) << endl;


}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  
