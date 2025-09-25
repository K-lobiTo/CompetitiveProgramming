
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
    vec<int> reversion(n);
    vec<int> idx(n);
    int inp;
    for (int i = 0; i < n; i++) {
        cin>>inp; inp--;
        reversion[inp] = i;
        idx[i] = inp;
    }

    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        if(reversion[i]>reversion[i+1]){
            ans++;
        }
    }
    auto ok = [&](int i) -> bool{
        return i>=0 && i<n;
    };

    // DEBUG(ans);

    int a, b;
    while(m--) {
        cin>>a>>b; a--; b--;
        int is = idx[a];
        int ib = idx[b];
        int mini = min(is, ib);
        int maxi = max(is, ib);
        set<pair<int, int>> ap;
        ap.insert({mini, maxi});
        if (ok(is-1)) ap.insert({is-1,is});
        if (ok(is+1)) ap.insert({is, is+1});
        if (ok(ib-1)) ap.insert({ib-1, ib});
        if (ok(ib+1)) ap.insert({ib, ib+1});

        for(auto &[f, s]:ap){
            if(f+1 == s && reversion[f] > reversion[s])ans--;
        }

        swap(idx[a], idx[b]);
        reversion[is] = b;
        reversion[ib] = a;

        for(auto &[f, s]:ap){
            if(f+1 == s && reversion[f] > reversion[s])ans++;
        }

        cout<<ans<<endl;
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


