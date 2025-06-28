#include <algorithm>
#include <bits/stdc++.h>
#include <ctime>
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
    int n, m; cin>>n>>m;
    vec<ll> h(n); rAuto(h);
    vec<ll> tck(m); rAuto(tck);
    multiset<ll> h2(ALL(h));
    for (int i = 0; i < m; i++) {
        auto it = h2.upper_bound(tck[i]);
        if(it==h2.begin())cout<<-1<<endl;
        else {
            --it;
            cout<<*it<<endl;
            h2.erase(it);
        }
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


