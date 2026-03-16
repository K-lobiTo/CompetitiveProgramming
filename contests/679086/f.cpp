#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, k, x; cin>>n>>k>>x;
    vec<int> a(n); for(auto &e:a)cin>>e;
    ranges::sort(a);
    ll bigrs = 0;
    ll tot = accumulate(a.begin(), a.end(), 0LL);
    ll rem = 0;
    for (int i = n - 1; i >= n-x; i--) {
        rem+=a[i];
    }

    int l = n-x-1;
    ll ans = tot-2*rem;
    // DEBUG(ans);
    for (int i = n - 1; i >= n-k; i--) {
        tot-=a[i];
        rem-=a[i];
        if(l>=0)rem+=a[l--];
        ans = max(ans, tot-2*rem);
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


