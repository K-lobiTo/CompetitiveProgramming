
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
  
void solve(){
    int n;cin>>n;
    vec<vec<int>> mat(n,vec<int>(n)); 
    for(auto &row: mat){
        for(auto &e: row)cin>>e;
    }
    int sum=0;
    vec<int> ans(2*n);
    for(int i =0 ;i<n; ++i){
        ans[1+i] = mat[0][i];
        sum+=ans[1+i];
    }
    for(int i = 1; i<n; ++i){
        ans[n+i] = mat[i][n-1];
        sum+=ans[n+i];
    }
    ans[0] = (((2*n*(2*n+1))/2)-sum);
    for(auto &e: ans)cout<<e<<' ';
    cout<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  