#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll n, h; cin>>n>>h;
    vec<ll> a(n); for(auto &e:a)cin>>e;
    vec<ll> tops(n, h);
    ll ans = 0;
    pair<ll, int> mx = {-1, -1};
    for (int i = 0; i < n; i++) {
        int l = i-1, r = i+1;
        ll llim = a[i], rlim = a[i];
        pair<ll, int> cur = {0, i};
        vec<ll> curtops(n, h);
        curtops[i] = a[i];
        cur.first+=h-a[i];
        while(l>=0){
            if(a[l]==h)break;
            llim = max(llim, a[l]);
            curtops[l] = llim;
            cur.first+=h-llim;
            l--;
        }
        while(r<n){
            if(a[r]==h)break;
            rlim = max(rlim, a[r]);
            curtops[r] = rlim;
            cur.first+=h-rlim;
            r++;
        }
        if(cur > mx){
            mx = cur;
            tops = curtops;
        }
    }
    ans += mx.first;

    // DEBUG(mx.first);
    // DEBUG(mx.second);

    mx = {-1, -1};

    for (int i = 0; i < n; i++) {
        int l = i-1, r = i+1;
        ll llim = a[i], rlim = a[i];
        pair<ll, int> cur = {0, i};
        cur.first+=tops[i]-a[i];
        while(l>=0 && a[l] < tops[l] && llim<tops[l]){
            llim = max(llim, a[l]);
            cur.first+=tops[l]-llim;
            l--;
        }
        while(r<n && a[r] < tops[r] && rlim<tops[r]){
            rlim = max(rlim, a[r]);
            cur.first+=tops[r]-rlim;
            r++;
        }
        mx = max(mx, cur);
    }
    // DEBUG(mx.first);
    // DEBUG(mx.second);
    ans+=mx.first;

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


