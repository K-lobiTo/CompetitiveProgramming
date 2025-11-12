#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
#define pll pair<ll, ll> 
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<int> b(n); rAuto(b);
    map<int, pll> reps;
    ll f = 1;
    vector<ll> ans;
    for(auto i : b) {
        if(reps.find(i) == reps.end()) {
            if(i != 1) {
                reps[i] = { i - 1, f };
            }
            ans.push_back(f);
            f++;
        }
        else {
            ans.push_back(reps[i].second);
            reps[i].first--;
            if(reps[i].first == 0) {
                reps.erase(i);
            }
        }
    }
    if(reps.size()) {
        cout << -1 << endl;
        return;
    }
    for(auto &e:ans)cout<<e<<' ';
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


