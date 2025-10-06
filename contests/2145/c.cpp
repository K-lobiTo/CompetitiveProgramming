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
    string s; cin>>s;
    vec<int> isbal(n);
    for (int i = 0; i < n; i++) {
        if(s[i] == 'a')isbal[i] = 1;
        else isbal[i] = -1;
    }

    isbal.insert(isbal.begin(), 0);
    partial_sum(ALL(isbal), isbal.begin());
    int d = isbal.back();
    if(!d)return void(cout<<d<<endl);

    int ans = n;
    map<int, int> inseg; inseg[0] = 0;
    for (int i = 1; i <= n; i++) {
        int c = isbal[i] - d;
        if(inseg.find(c) != inseg.end()){
            ans = min(ans, i - inseg[c]);
        }
        inseg[isbal[i]] = i;
    }
    cout<<(ans==n  ? -1: ans)<<endl;
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


