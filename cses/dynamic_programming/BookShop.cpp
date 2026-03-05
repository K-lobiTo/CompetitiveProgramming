#include <algorithm>
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

struct book{
    int h;
    int s;
};

void solve(){
    int n, x; 
    cin>>n>>x;
    vec<book> b(n);
    vec<ll> dp(x+1001, 0);
    for (int i = 0; i < n; i++) cin>>b[i].h;
    for (int i = 0; i < n; i++) cin>>b[i].s;


    for (int i = 0; i < n; i++) {
        for (int cost = x; cost >= b[i].h; cost--) {
            dp[cost] = max(dp[cost], dp[cost-b[i].h] + b[i].s);
        }
    }

    cout<<dp[x]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


