
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
    vec<pair<int, int>> x(n);
    vec<int> oIdxs(n);
    for (int i = 0; i < n; i++) {
        x[i] = {0, i+1};
        cin>>x[i].first;
        oIdxs[i] = x[i].first-1;
    }
    sort(ALL(x));

    int ans = 1;
    int idx = x[0].second;
    for (int i = 1; i < n; i++) {
        if(x[i].second < idx){
            ans++;
        }
        idx = x[i].second;
    }
    cout<<ans<<endl;
    cout<<endl;

    // I was thinking about using a map
    // but it would take O(n) each query anyway
    int a, b;
    for (int i = 0; i < m; i++) {
        cin>>a>>b; a--; b--;
        int mini = min(a, b);
        int maxi = max(a, b);
        if(oIdxs[mini]<oIdxs[maxi])ans++;
        else ans--;
        cout<<ans<<endl;
        swap(oIdxs[mini], oIdxs[maxi]);
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


