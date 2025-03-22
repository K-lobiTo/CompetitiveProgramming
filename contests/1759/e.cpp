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
int n;
  
int dp(vec<int> &ast,ll h,  int g, int b, ll i){
    if(i==n)return 0;
    if(ast[i]<h)
        return 1 + dp(ast, h+ast[i]/2, g, b, i+1);
    ll takeb = 0, takeg = 0;
    if(g)takeg = dp(ast, h*2, g-1, b, i);
    if(b)takeb = dp(ast, h*3, g, b-1, i);
    return max(takeg, takeb);
}
void solve(){
    cin>>n;
    ll h;cin>>h;
    vec<int> ast(n);
    for(auto&e:ast)cin>>e;
    sort(ALL(ast));
    cout<<dp(ast, h, 2, 1, 0)<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  