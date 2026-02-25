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
    vec<int> p(n); rAuto(p);

    vec<int> maxsuf(n+2, -1);
    vec<int> minpref(n+1, n);

    for (int i = 1; i < n+1; i++) {
        minpref[i] = min(minpref[i-1], p[i-1]);
    }

    for (int i = n; i > 0; i--) {
        maxsuf[i] = max(maxsuf[i+1], p[i-1]);
    }

    for (int i = 1; i <= n; i++) {
        if(minpref[i-1]>maxsuf[i])return void(cout<<"No"<<endl);
    }
    cout<<"Yes"<<endl;
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


