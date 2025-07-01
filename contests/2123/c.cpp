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
    vec<int> a(n); rAuto(a);
    vec<int> mins(n+1); // idx in 1
    vec<int> maxs(n+1); // tambien
    mins[0] = int(1e6 +1);
    for (int i = 0; i < n; i++) {
        mins[i+1] = min(mins[i], a[i]);
    }
    maxs[n] = - int(1e6 +1);
    for (int i = n - 1; i >= 0; i--) {
        maxs[i] = max(maxs[i+1], a[i]);
    }
    for (int i = 0; i < n; i++) {
        if(mins[i]>=a[i] || maxs[i+1]<=a[i])cout<<1;
        else cout<<0;
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


