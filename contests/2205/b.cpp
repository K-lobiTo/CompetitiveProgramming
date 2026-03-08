#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

vec<vec<int>> criba(MAX);
void fillCriba(){
    int indx = 0;
    for (int i = 2; i < MAX; i++) {
        if(criba[i].empty()) {
            for (int j = i; j < MAX; j+=i) {
                criba[j].push_back(i);
            }
        }
    }
}
  
void solve(){
    ll n; cin>>n;
    ll nf = n;
    map<ll, int> primefacts;
    for (ll i = 2; i*i <= nf; i++) {
        while(!(nf%i)){
            primefacts[i]++;
            nf/=i;
        }
    }
    if(nf>1)primefacts[nf]++;

    ll ans = 1;
    for(auto &[f, c]:primefacts)ans*=f;
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    fillCriba();
    while(t--){
        solve();
    }
    return 0;
}


