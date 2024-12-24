
#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

ll mylogb4(ll v){
    ll l = 0, h = v, m;
    while (h-l>1){
        m = floor((l+h)/2);
        // DEBUG(m);
        // DEBUG(l);
        // DEBUG(h);
        if(pow(4, m)<=v){
            l = m;
        }
        else{h = m;}
    }
    return l;
}

void solve(){
    ll n;
    cin>>n;
    if(n<4){cout<<"1\n"; return;}
    // ll ans = pow(2, floor(log(n)/log(4)));
    ll ans = pow(2, mylogb4(n));
    cout<<ans<<'\n';
    return;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  