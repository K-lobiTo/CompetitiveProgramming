#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vec<int> nOp(n+1, n+1);
    vec<int> acc(n+1);
    for (int i = n-1; i >= 0; i--) {
        nOp[i] = (s[i] == '(' ? i:nOp[i+1]);
        acc[i] = acc[i+1]+(s[i] == '(');
    }
    int ans = -1;
    for (int i = 0; i < n; i++) {
        if(s[i] == ')' && nOp[i]<=n){
            int cbr = (nOp[i]-i);
            if(acc[nOp[i]+1] >= cbr)ans = max(ans,n - 2 * cbr);
        }
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


