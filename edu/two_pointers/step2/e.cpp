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
    vec<int> a(n); rAuto(a);
    set<int> elem;
    int l = 0;
    ll ans = 0;
    map<int, int> reps;
    for (int r = 0; r < n; r++) {
        elem.insert(a[r]);
        reps[a[r]]++;
        while(elem.size()>k){
            if(! --reps[a[l]]) elem.erase(a[l]);
            l++;
        }
        ans+=r-l+1;
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


