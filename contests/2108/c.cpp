#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<int> a(1, -1);
    for (int i = 1; i < n+1; i++) {
        int inp; cin>>inp;
        if(inp == a.back())continue;
        a.push_back(inp);
    }
    a.push_back(-1);
    if(n<=2)return void(cout<<1<<endl);
    int ans = 0;
    for (int i = 1; i < (int)a.size(); i++) {
        if(a[i-1] < a[i] && a[i+1]<a[i])ans++;
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


