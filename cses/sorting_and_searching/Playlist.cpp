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
    int n; cin>>n;
    vec<ll> k(n); rAuto(k);
    int ans = 0;
    int l = 0;
    multiset<int> inseg;
    for (int i = 0; i < n; i++) {
        inseg.insert(k[i]);
        auto it = inseg.equal_range(k[i]);
        while(it.first != prev(it.second)){
            inseg.erase(inseg.find(k[l]));
            it = inseg.equal_range(k[i]);
            l++;
        }
        ans = max(ans, i-l + 1);
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


