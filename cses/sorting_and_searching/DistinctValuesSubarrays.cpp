#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<int> a(n); for(auto &e:a)cin>>e;
    multiset<int> current;
    int l = 0;
    ll ans = 0;
    for (int r = 0; r < n; r++) {
        current.insert(a[r]);
        while(current.count(a[r])>1)current.erase(current.find(a[l++]));
        ans+=current.size();
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


