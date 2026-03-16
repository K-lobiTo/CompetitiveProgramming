#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n); for(auto &e:a)cin>>e;
    vec<ll> prefpos(n), sufnegs(n);
    for (int i = 0; i < n; i++) {
        if(a[i]>0)prefpos[i] = a[i];
        if(i)prefpos[i] += prefpos[i-1];
        // prefpos[i] += (i && a[i]>0 ? prefpos[i-1]: 0);
    }
    for (int i = n-1; i >= 0; i--) {
        if(a[i]<0) sufnegs[i] = abs(a[i]);
        if(i+1<n)sufnegs[i]+=sufnegs[i+1];
        // sufnegs[i] += (i+1<n && a[i]<0 ? sufnegs[i+1] : 0);
    }
    // for(auto &e:prefpos)cout<<e<<" ";
    // cout<<endl;
    // for(auto &e:sufnegs)cout<<e<<" ";
    // cout<<endl;

    ll ans = sufnegs[0];
    sufnegs.push_back(0);
    for (int i = 0; i < n; i++) {
        ans = max(ans, prefpos[i] + sufnegs[i+1]);
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


