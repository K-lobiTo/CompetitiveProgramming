#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, k, x; cin>>n>>k>>x;
    vec<int> a(n); for(auto &e:a)cin>>e;
    a.push_back(-x);
    a.push_back(x+1);
    ranges::sort(a);


    auto chk = [&](int m) -> set<int>{
        a[0] = -m;
        a.back() = x + m;
        set<int> subans;
        for (int i = 0; i <= n; i++) {
            int next = a[i+1] - m;
            for (int v = a[i]+m; v <= next ; v++) {
                subans.insert(v);
                if(subans.size()==k) return subans;
            }
        }
        return {};
    };

    ll l = 0, r = x+1;
    while(l+1 < r){
        ll m = (l+r)/2;
        a.back() = x + m;
        if(chk(m).size())l = m;
        else r = m;
    }
    
    for(auto &e:chk(l))cout<<e<<" ";
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


