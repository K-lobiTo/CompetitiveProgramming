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
    int n, m; cin>>n>>m;
    vec<string> input(n);
    vec<string> ans(n, "");
    for(auto &e:input)cin>>e;
    ll p = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(p&1){
                if(input[i][j] == 'C' || input[i][j] == 'D'){
                    ans[i]+='A';
                }
                else ans[i]+='D';
            }
            else{
                if(input[i][j] == 'C' || input[i][j] == 'D'){
                    ans[i]+='B';
                }
                else ans[i]+='C';
            }
            p++;
        }
        p-=(!(m&1));
    }
    for(auto &e:ans)cout<<e<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


