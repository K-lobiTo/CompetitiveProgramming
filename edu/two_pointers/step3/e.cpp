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
    int n, s; cin>>n>>s;
    vec<pair<ll, ll>> wc(n);
    for (int i = 0; i < n; i++) {
        cin>>wc[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin>>wc[i].second;
    }
    int l = 0;
    pair<ll, ll> cur = {0, 0};
    ll ans = -1e9;
    for (int i = 0; i < n; i++) {
        cur.first += wc[i].first;
        cur.second += wc[i].second;
        while(cur.first > s){
            cur.first -= wc[l].first;
            cur.second -= wc[l].second;
            l++;
        }
        ans = max(ans, cur.second);
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


