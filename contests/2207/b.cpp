#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m, l; cin>>n>>m>>l;
    vec<int> a(n); for(auto &e:a)cin>>e;
    ranges::sort(a);

    int L = 0, R = MAX;
    // while(L+1 < R){
    //     int M = (L+R)/2;
    // }
    cout<<R-1<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


