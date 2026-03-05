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
    bitset<size_t(1e6+2)> ans;
    ans[0] = 1;
    int n, inp; cin>>n;
    for (int i = 0; i < n; i++) {
        cin>>inp;
        ans|=ans<<inp;
    }
    vec<int> subans;
    for (int i = 1; i < n*(1e3) +2; i++) {
        if(ans[i])subans.push_back(i);
    }
    cout<<subans.size()<<endl;
    for(auto &e:subans)cout<<e<<' ';
    cout<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


