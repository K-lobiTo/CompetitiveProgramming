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
    ll tot = 0;
    for (int i = 0; i < n; i++) {
        tot += (i&1 ? -a[i] : a[i]);
    }
    // DEBUG(tot);
    if(n==1)return void(cout<<a[0]<<endl);
    vec<ll> prefmn(n), sufmn(n); // it's actually max but I won't change the names
    for (int i = 0; i < n; i++) {
        if(i&1){
            prefmn[i] = prefmn[i-1] + 1;
            continue;
        }
        prefmn[i] = (i && (prefmn[i-1] + 1 > (-2*a[i])) ? prefmn[i-1] + 1 : -2*a[i]);
    }
    for (int i = n-1; i >= 0; i--) {
        if(i&1){
            sufmn[i] = (i+1<n ? sufmn[i+1] + 1 : -1e12);
            continue;
        }
        sufmn[i] = (i+1<n && (sufmn[i+1] + 1 > (-2*a[i])) ? sufmn[i+1] + 1 : -2*a[i]);
    }
    // for(auto &e:prefmn)cout<<e<<" ";
    // cout<<endl;
    // for(auto &e:sufmn)cout<<e<<" ";
    // cout<<endl;


    ll ans = tot;
    int idxans = -1;
    for (int i = 1; i < n; i+=2) {
        if(ans < tot + 2*a[i] + max(sufmn[i], prefmn[i])){
            idxans = i;
            ans = tot + 2*a[i] + max(sufmn[i], prefmn[i]);
        }
    }
    // DEBUG(idxans);
    if(n > 2){
        ans=max(ans, tot + (n&1 ? n-1 : n-2));
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


