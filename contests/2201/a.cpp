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
    int ans = n;
    bool inc = 0;
    int l = a[0], r = a[0]-1;
    for (int i = 1; i < n; i++) {
        if(a[i]==a[i-1]+1){
            ans--;
            r = max(r, a[i]);
        }
        else if(a[i]>l && a[i]<=r){
            ans--;
            r = a[i];
        }
        else {
            l = a[i], r = a[i]-1;
        }
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


