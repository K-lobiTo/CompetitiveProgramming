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
int n, k, l, r; 
vec<ll> a; 
ll tp(int msize, int mdiff){
    ll ans = 0;
    int ml = 0;
    int subans = 0;
    unordered_map<int, int> inseg;
    for (int i = 0; i < n; i++) {
        inseg[a[i]]++;
        if(inseg[a[i]] == 1)subans++;
        while(subans>mdiff || (i-ml +1)>msize){
            inseg[a[ml]]--;
            if(!inseg[a[ml]])subans--;
            ml++;
        }
        ans += i-ml + 1;
    }
    return ans;
}
  
void solve(){
    cin>>n>>k>>l>>r;
    a.resize(n);
    rAuto(a);
    ll ans = tp(r, k) - tp(r, k-1) - tp(l-1, k) + tp(l-1, k-1);
    cout<<ans<<endl;
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


