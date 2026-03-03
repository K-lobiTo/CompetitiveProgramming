#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    map<int, int> a;
    for (int i = 0; i < n; i++) {
        int input; cin>>input;
        a[input]++;
    }
    vec<int> pairs;
    vec<int> single;
    for(auto &[v, cant]:a){
        if(cant&1){
            single.push_back(v);
        }
        for (int i = 0; i < cant - (cant&1); i++) {
            pairs.push_back(v);
        }
    }

    int bstsingle = 0;
    ll ans = accumulate(pairs.begin(), pairs.end(), 0LL);
    auto it = ranges::lower_bound(single, ans);
    if(it != single.begin()){
        it--;
        bstsingle = *it;
        ans+=bstsingle;
        single.erase(it);
    }
    it = ranges::lower_bound(single, ans);
    if(it != single.begin()){
        it--;
        bstsingle = *it;
        ans+=bstsingle;
        single.erase(it);
    }
    

    if(pairs.size() == 2 && !bstsingle) return void(cout<<0<<endl);
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


