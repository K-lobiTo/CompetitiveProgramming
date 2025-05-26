#include <algorithm>
#include <bits/stdc++.h>
#include <regex>
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
    int n; cin>>n;
    vec<pair<pair<ll, ll>, int>> xy(n);
    vec<pair<pair<ll, ll>, int>> yx(n);
    int idx = 0;
    set<pair<ll, ll>> inRect;
    for(auto &[XY, i]:xy){
        cin>>XY.first>>XY.second;
        i = idx; idx++;
        inRect.insert({XY.first, XY.second});
    }
    idx = 0;
    for(auto &[YX, i]:yx){
        YX.second = xy[idx].first.first;
        YX.first = xy[idx].first.second;
        i = xy[idx].second;
        idx++;
    }

    if(n==1){cout<<1<<endl;return;}

    sort(ALL(xy));
    sort(ALL(yx));
    ll miniArea = (ll)2e18; 
    for (int p = 0; p < n; p++) {
        ll left = -1, right = -1, up = -1, down = -1;
        for (int i = 0; i < 2; i++) {
            if(xy[i].second != p){left = xy[i].first.first;break;}
        }
        for (int i = 1; i < 3; i++) {
            if(xy[n-i].second != p){right = xy[n-i].first.first;break;}
        }
        for (int i = 0; i < 2; i++) {
            if(yx[i].second != p){up = yx[i].first.first; break;}
        }
        for (int i = 1; i < 3; i++) {
            if(yx[n-i].second != p){down = yx[n-i].first.first; break;}
        }
        ll area = (right-left+1)*(down-up+1);
        if (area == n-1)area+=min(max(0LL, right-left+1), max(0LL, down-up+1));
        if(area<miniArea){
            miniArea = area;
        }
    }
    cout<<miniArea<<endl;
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


