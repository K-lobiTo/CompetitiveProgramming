#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

ll gauss(ll v){
    return ((v*(v+1))/2)%MOD;
}

  
void solve(){
    int n; cin>>n;
    map<int, int> x; 
    for (int i = 0; i < n; i++) {
        int input; cin>>input;
        x[input]++;
    }
    ll ans = 1;
    for(auto &[v, c]:x){
        ans*=(c+1);
        ans%=MOD;
    }
    ans--;
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


