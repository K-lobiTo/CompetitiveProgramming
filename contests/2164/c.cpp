#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m; cin>>n>>m;
    multiset<int> a;
    vec<pair<int, int>> cb(m);
    for (int i = 0; i < n; i++) {
        int input; cin>>input;
        a.insert(input);
    }

    for(auto &e:cb)cin>>e.second;
    for(auto &e:cb)cin>>e.first;


    vec<pair<int, int>> cb1;
    vec<pair<int, int>> cb2;

    for (int i = 0; i < m; i++) {
        if(cb[i].first)cb1.push_back(cb[i]);
        else cb2.push_back(cb[i]);
    }

    ranges::sort(cb1, [&](pair<int, int> f, pair<int, int> s) -> bool {
            if(f.second == s.second)return f.first > s.first;
            return f.second < s.second;
            });

    ranges::sort(cb2, [&](pair<int, int> f, pair<int, int> s) -> bool {
            return f.second < s.second;
            });


    int ans = 0;
    for (int i = 0; i < cb1.size(); i++) {
        auto it = a.lower_bound(cb1[i].second);
        if(it != a.end()){
            ans++;
            int val = *it;
            a.erase(it);
            a.insert(max(cb1[i].first, val));
        }
        else break;
    }
    for (int i = 0; i < cb2.size(); i++) {
        auto it = a.lower_bound(cb2[i].second);
        if(it != a.end()){
            ans++;
            a.erase(it);
        }
        else break;

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


