#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll l, r; cin>>l>>r; //l is always 0
    ll n = r - l + 1;
    vec<int> a(n);
    // int k = bit_ceil((unsigned int) r) - 1;
    int k = 1; while(k < r) k = k<<1 | 1;
    set<int> s;
    for(int e: views::iota(l, r+1))s.insert(e);

    ll ans = 0;

    for (int i = r; i >= l; i--) {
        while(!s.contains(k-i))
            k >>= 1;
        a[i] = k - i;
        ans += i | a[i];
        s.erase(k - i);
    }
    cout<<ans<<endl;
    for(auto &e:a)cout<<e<<' ';
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


