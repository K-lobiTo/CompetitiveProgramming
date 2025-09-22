#include <bits/stdc++.h>
#include <numeric>
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
    vec<ll> a(n); rAuto(a);
    ll sum = accumulate(ALL(a), 0LL);
    for (int f = 0; f < 2; f++) {
        vec<int> vis(n+1);
        ll curmax = 0;
        for (int i = 0; i < n; i++) {
            if(a[i]>curmax && vis[a[i]]){
                curmax = a[i];
            }
            vis[a[i]] = 1;
            a[i] = curmax;
            if(!f)sum+=curmax;
        }
    }
    for (int i = 0; i < n; i++) {
        sum+=a[i] * (n-i);
    }

    cout<<sum<<endl;
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


