#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define ld long double

const int MAX = 2e5+20, MOD = 1e9+7;
const long double epsi = 1e-6;
int t=1;

  
void solve(){
    int n; cin>>n;
    vec<int> c(n), p(n);
    for (int i = 0; i < n; i++) {
        cin>>c[i]>>p[i];
    }
    ld ans = c[n-1];
    for (int i = n - 2; i >= 0; i--) {
        ans = max(ans, c[i] + ans*(1.0 - (p[i]/100.0)));
    }

    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cout<<fixed<<setprecision(7);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


