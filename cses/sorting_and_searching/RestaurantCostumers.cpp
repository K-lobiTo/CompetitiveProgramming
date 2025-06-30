#include <algorithm>
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
    int n; cin>>n;
    int a, b;
    vec<pair<int, int>> inp;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        inp.push_back({a, 1});
        inp.push_back({b+1, -1});
    }
    sort(ALL(inp));
    int curr = 0;
    int idx = 0;
    vec<int> changes(2 *n);
    for (int i = 0; i < 2*n; i++) {
        if(i && inp[i].first > curr){
            curr = inp[i].first;
            idx++;
        }
        changes[idx+1] += inp[i].second;
    }
    partial_sum(ALL(changes), changes.begin());
    cout<<*max_element(ALL(changes))<<endl;
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


