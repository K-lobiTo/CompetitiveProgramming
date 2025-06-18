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
    vec<pair<ll, string>> sAns;
    string in;
    for (int i = 0; i < m; i++) {
        cin>>in;
        ll val = stoll(in.substr(0, in.size()-2));
        sAns.push_back({val, in});
    }
    sort(ALL(sAns));
    vec<vec<string>> ans(n);
    for (int i = 0; i < n; i++) {
        for(int j = 0; j <6; j++) {
            if(j&1){
                if(i&1)ans[i].push_back(sAns[i/2].second);
                else{ans[i].push_back(sAns[m-i/2-1].second);}
            }
            else{
                if(i&1)ans[i].push_back(sAns[m-i/2-1].second);
                else{ans[i].push_back(sAns[i/2].second);}
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            cout<<ans[i][j]<<' ';
        }
        cout<<endl;
    }
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


