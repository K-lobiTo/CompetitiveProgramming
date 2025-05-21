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
    int n; cin>>n; 
    vec<vec<int>> ans(1<<n, vec<int>(n, 0));
    int jump = 1;
    int column = (n-1);
    while (column>=0){
        for(int i = jump; i<(1<<n); i+=(jump*2)){
            for(int m = 0; m<(jump*2) && (i+m)<(1<<n);++m){
                ans[i+m][column]=1;
            }
            i+=(jump*2);
        }
        column--;
        jump*=2;
    }
    
    for(auto &row: ans){
        for(auto &e:row){
            cout<<e;
        }
        cout<<'\n';
    }
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  