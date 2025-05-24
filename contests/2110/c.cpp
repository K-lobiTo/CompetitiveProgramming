#include <bits/stdc++.h>
#include <numeric>
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
    int n;cin>>n;
    vec<int> d(n);
    rAuto(d);

    vec<pair<int, int>> lr(n);
    for(int i = 0; i<n; ++i){
        cin>>lr[i].first>>lr[i].second;
    }

    vec<int> nd(ALL(d));
    for(auto &e:nd)if(e==-1)e = 0;

    vec<int> hs(ALL(nd));
    partial_sum(ALL(hs), hs.begin());

    for(int i = 0; i<n; ++i){
        if(lr[i].second<hs[i]){cout<<-1<<endl;return;}
    }

    hs.push_back((int)1e10);
    for (int i = n - 1; i >= 0; i--) {
        hs[i] = min(lr[i].second - hs[i], hs[i+1]);
    }

    int h = 0, changed = 0;
    for (int i = 0; i < n; i++) {
        if(d[i]==-1){
            if(changed<hs[i])changed++, nd[i] = 1;
        }
        h+=nd[i];
        if(h<lr[i].first || h>lr[i].second){cout<<-1<<endl;return;}
    }

    for(auto &e:nd)cout<<e<<' ';
    cout<<endl;
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


