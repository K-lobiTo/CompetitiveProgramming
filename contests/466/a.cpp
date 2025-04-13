
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
int m, a, b;
int memo[2002];
int vis[1001];

int rec(int rubles, int n){
    if(n<=0)return rubles;
    if(vis[n])return memo[n];
    vis[n] = 1;
    return memo[n] = min(rec(rubles+a, n-1), rec(rubles+b, n-m));
}
  
int dp(int n){
    if(n<0)return 0;
    if(n==0){
        vis[n] = 1;
        return 0;
    }
    if(vis[n])return memo[n];
    vis[n] = 1;
    return memo[n] = min(a + dp(n-1), b+dp(n-m));
}

void solve(){
    int n;cin>>n>>m>>a>>b; 
    cout<<rec(0, n)<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  