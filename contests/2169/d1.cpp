#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const ll MAX = 1e12+1, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll x, y, k; cin>>x>>y>>k;

    ll l = 0, r = MAX;
    while(l+1 < r){
        ll mid = (l + r)/2;
        ll rem = mid;
        for (int i = 0; i < x; i++) {
            rem -= rem/y;
        }
        if(rem >= k)r = mid;
        else l = mid;
    }


    if(r == MAX)cout<<-1<<endl;
    else cout<<r<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


