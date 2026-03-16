#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll a, b, c, m; cin>>a>>b>>c>>m;
    ll ansA, ansB, ansC;
    ansA = 6*(m/a);
    ansB = 6*(m/b);
    ansC = 6*(m/c);

    ll Cab = m/lcm(a,b);
    ll Cac = m/lcm(a,c);
    ll Cbc = m/lcm(b,c);
    ll Cabc = m/lcm(a,lcm(b, c));

    ansA += 2*Cabc;
    ansA -= 3*Cab;
    ansA -= 3*Cac;

    ansB += 2*Cabc;
    ansB -= 3*Cab;
    ansB -= 3*Cbc;

    ansC += 2*Cabc;
    ansC -= 3*Cac;
    ansC -= 3*Cbc;

    cout<<ansA<<" "<<ansB<<" "<<ansC<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


