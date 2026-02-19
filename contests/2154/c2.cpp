#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

vec<vec<int>> criba(MAX);
vec<int> primes;
void fillCriba(){
    int indx = 0;
    for (int i = 2; i < MAX; i++) {
        if(criba[i].empty()) {
            primes.push_back(i);
            for (int j = i; j < MAX; j+=i) {
                criba[j].push_back(i);
            }
        }
    }
}
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n), b(n); rAuto(a); rAuto(b);
    vec<ll> oddValCosts;
    for (int i = 0; i < n; i++) {
        if(a[i]&1)oddValCosts.push_back(b[i]);
    }

    vec<int> ord(n); iota(ALL(ord), 0);
    sort(ALL(ord), [&](int x, int y) -> bool{
            return b[x] < b[y];
            });

    set<int> divis;
    for(const auto &e:a){
        for(const auto &p:criba[e]){
            if(!divis.insert(p).second){ 
                cout<<0<<endl;
                return;
            }
        }
        divis.insert(e);
    }

    sort(ALL(oddValCosts));
    ll ans = b[ord[0]] + b[ord[1]];


    int idx = ord[0];
    set<int> check;
    for (int i = 0; i < n; i++) {
        if(i==idx)continue;
        for(auto &e:criba[a[i]])check.insert(e);
    }
    for(int i = 0; i<n; i++){
        int e = a[i];
        for(auto &d:criba[e+1]){
            if(divis.contains(d)){
                ans = min(ans, b[i]);
            }
        }
    }
    for(auto &e:check){
        int times = (e - (a[idx]%e))%e;
        ans = min(ans, b[idx]*times);
    }
    
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    fillCriba();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}



