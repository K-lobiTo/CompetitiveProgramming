#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){
    int n; cin>>n;
    vec<int> p(n);
    for(auto &e:p)cin>>e;

    vec<int> maxsuf(n+2, -1);
    vec<int> minpref(n+1, n);

    for (int i = 1; i < n+1; i++) {
        minpref[i] = min(minpref[i-1], p[i-1]);
    }

    for (int i = n; i > 0; i--) {
        maxsuf[i] = max(maxsuf[i+1], p[i-1]);
    }
    set<pair<int, int>> ans;

    for (int i = 1; i <= n; i++) {
        if(minpref[i-1]>maxsuf[i])return void(cout<<"No"<<endl);
    }
    cout<<"Yes"<<endl;
    int r = -1;
    vec<int> toConn;
    for (int i = n - 1; i >= 0; i--) {
        if(maxsuf[i+1] == p[i]){
            while(toConn.size())ans.insert({toConn.back(), r}), toConn.pop_back();
            if(r != -1){
                ans.insert({minpref[i], r});
            }
            r = p[i];
        }
        else{
            toConn.push_back(p[i]);
        }
    }
    while(toConn.size())ans.insert({toConn.back(), r}), toConn.pop_back();

    for(auto &[v, u]:ans){
        cout<<v<<" "<<u<<endl;
    }
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


