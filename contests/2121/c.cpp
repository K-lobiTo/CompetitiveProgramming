#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m; cin>>n>>m;
    int input;
    vec<pair<ll, pair<int, int>>> sAns;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>input;
            sAns.push_back({input, {i, j}});
        }
    }
    sort(ALL(sAns)); 
    if(n==1 || m==1){cout<<sAns.back().first-1<<endl;return;}
    int x1, y1, x2, y2;
    int maxi = sAns.back().first;
    x1 = sAns.back().second.first ;
    y1 = sAns.back().second.second ;
    x2 = x1;
    y2 = y1;
    for (ll i = n*m-2; i >= 0; i--) {
        if(sAns[i].first != maxi)break;
        if((sAns[i].second.first != x1 && sAns[i].second.second != y1)){
            x2 = sAns[i].second.first;
            y2 = sAns[i].second.second;
            break;
        }
    }
    // x2 = sAns[n*m-1].second.first;
    // y2 = sAns[n*m-1].second.second;
    bool flag = true;
    for (ll i = n*m-1; i >= 0; i--) {
        if(sAns[i].first != maxi)break;
        if(!(sAns[i].second.first == x1 || sAns[i].second.second == y2)){flag = false;break;}
    }
    if(flag){cout<<maxi-1<<endl; return;}
    flag = true;
    for (ll i = n*m-1; i >= 0; i--) {
        if(sAns[i].first != maxi)break;
        if(!(sAns[i].second.first == x2 || sAns[i].second.second == y1)){flag = false;break;}
    }
    cout<<(flag?maxi-1 : maxi)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


