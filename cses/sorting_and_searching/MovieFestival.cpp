#include <algorithm>
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
    int n; cin>>n;
    int a, b;
    vec<pair<int, int>> input;
    for (int i = 0; i < n; i++) {
        cin>>a>>b;
        input.push_back({a,b});
        input.push_back({b,0});
    }
    sort(ALL(input));
    set<int> open;
    int count = 0;
    for (int i = 0; i < 2*n; i++) {
        if(!input[i].second){
            if(open.find(input[i].first) != open.end()){
                count++;
                open.erase(ALL(open));
            }
        }
        else open.insert(input[i].second);
    }
    cout<<count<<endl;
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


