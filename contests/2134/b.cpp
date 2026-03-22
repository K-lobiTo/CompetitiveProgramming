#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, k; cin>>n>>k;
    vec<ll> a(n); for(auto &e:a)cin>>e;
    int g = 2;
    while(gcd(g, k)!=1)g++;
    for(auto &e:a)
        while(e%g)e+=k;
    for(auto &e:a)cout<<e<<" ";
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


