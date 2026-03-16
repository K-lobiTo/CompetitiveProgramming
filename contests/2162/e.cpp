#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n,k; cin>>n>>k;
    vec<bool> vis(n+1);
    vec<int> order;
    vec<int> a(n); for(auto &e:a)cin>>e;
    for (int i = n-1; i >= 0; i--) {
        if(!vis[a[i]])order.push_back(a[i]), vis[a[i]] = 1;
        a[i] = a[i];
    }
    ranges::reverse(order);

    int f = order.back();
    bool ch = 0;
    if(f == a[n-1])order.pop_back(), ch = 1;

    int nonvis = 0;
    for (int i = 1; i <= n; i++) {
        if(!vis[i])order.push_back(i), nonvis++;
    }

    if(nonvis)ranges::reverse(order);
    if(ch)order.push_back(f);
    int it = 0;

    while(k--){
        cout<<order[it++%order.size()]<<" ";
    }
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


