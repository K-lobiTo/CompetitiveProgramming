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
  
void solve(){
    int n, Ax, Ay, Bx, By; cin>>n>>Ax>>Ay>>Bx>>By;
    vec<pair<int, int>> cords(n); 
    int input;
    for (int i = 0; i < n; i++) {
        cin>>cords[i].first;
    }
    for (int i = 0; i < n; i++) {
        cin>>cords[i].second;
    }
    
    sort(ALL(cords));

    map<int, pair<int, int>> rowrange;
    for (int i = 0; i < n; i++) {
        if(!rowrange.contains(cords[i].first)){
                rowrange[cords[i].first] = {1e10, -1e10};
        }
        rowrange.at(cords[i].first).first = min(cords[i].second, rowrange.at(cords[i].first).first);
        rowrange.at(cords[i].first).second = max(cords[i].second, rowrange.at(cords[i].first).second);

    }
    int x = Ax, y = Ay;
    vec<vec<pair<ll, ll>>> dp(rowrange.size() + 1, vec<pair<ll, ll>>(2));
    dp[0][0].second = y; //end up   -start with max
    dp[0][1].second = y; //end down -start with min
    int idx = 0;
    for(auto &[cx, range]:rowrange){
        ll r = range.second-range.first;
        ++idx;
        dp[idx][0].first = r + min(dp[idx-1][0].first + abs(dp[idx-1][0].second - range.first), dp[idx-1][1].first + abs(dp[idx-1][1].second - range.first));
        dp[idx][0].second = range.second;
        dp[idx][1].first = r + min(dp[idx-1][0].first + abs(dp[idx-1][0].second - range.second), dp[idx-1][1].first + abs(dp[idx-1][1].second - range.second));
        dp[idx][1].second = range.first;
        x = cx;
    }

    dp[idx][0].first+=abs(By-dp[idx][0].second);
    dp[idx][1].first+=abs(By-dp[idx][1].second);

    cout<<(min(dp[idx][0].first, dp[idx][1].first) + (Bx-Ax))<<endl;


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

