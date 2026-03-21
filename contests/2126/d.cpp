#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n, k; cin>>n>>k;
    vec<pair<int, pair<int, int>>> rangs(n);
    for(auto &R:rangs)cin>>R.first>>R.second.first>>R.second.second;
    ranges::sort(rangs);

    for(auto &[l, prv]:rangs){
        if(l>k)break;
        k = max(k, prv.second);
    }
    cout<<k<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


