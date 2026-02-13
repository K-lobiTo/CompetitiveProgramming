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
    vec<int> a(n), b(n); rAuto(a); rAuto(b);
    set<int> divis;
    for(const auto &e:a){
        for(const auto &p:criba[e]){
            if(!divis.insert(p).second){ 
                cout<<0<<endl;
                return;
            }
        }

        
    }
    for(const auto &e:a){
        for(auto &p:criba[e+1]){
            if(divis.contains(p)){
                cout<<1<<endl;
                return;
            }
        }
    }
    cout<<2<<endl;
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



