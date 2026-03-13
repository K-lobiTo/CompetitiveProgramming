#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll n, k; cin>>n>>k;
    vec<bool> s(n);
    for (int i = 0; i < n; i++) {
        char v; cin>>v;
        s[i] = v == '1';
    }
    vec<ll> a(n, -1e13);
    for (int i = 0; i < n; i++) {
        ll v; cin>>v;
        if(s[i])a[i] = v;
    }
    vec<ll> mxpref(n);
    vec<ll> mxsuf(n);
    for (int i = 0; i < n; i++) {
        mxpref[i] = (i && ( mxpref[i-1] + a[i] > a[i] ) ? mxpref[i-1] + a[i] : a[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
        mxsuf[i] = (i+1<n && (mxsuf[i+1] + a[i] > a[i]) ? mxsuf[i+1] + a[i] : a[i]);
    }
    ll mxall = *ranges::max_element(mxpref);
    if(mxall > k)return void(cout<<"No"<<endl);
    if(mxall == k){
        cout<<"Yes"<<endl;
        for(auto &e:a)cout<<e<<" ";
        cout<<endl;
        return;
    }
    bool ok = 0;
    for (int i = 0; i < n; i++) {
        if(!s[i]){
            ll l = (i ? max(0LL, mxpref[i-1]) : 0LL);
            ll r = (i+1<n ? max(0LL, mxsuf[i+1]) : 0LL);
            a[i] = k - l - r;
            ok = 1;
            break;
        }
    }
    if(ok){
        cout<<"Yes"<<endl;
        for(auto &e:a)cout<<e<<" ";
        cout<<endl;
        return;
    }
    cout<<"No"<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


