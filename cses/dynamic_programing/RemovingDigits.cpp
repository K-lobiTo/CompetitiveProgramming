#include <bits/stdc++.h>
#include <string>
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
int dp[1000001];

int calc(int a){
    if(!a) return dp[a] = 0;
    if(dp[a]) return dp[a];
    string cur = to_string(a);
    int c = 1e9;
    for (int i = 0; i < cur.size(); i++) {
        if(cur[i]!='0')c = min(c, calc(a - (cur[i]-'0')));
    }
    return dp[a] = c+1;
}
  
void solve(){
    int n; cin>>n;
    cout<<calc(n)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


