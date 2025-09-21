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
    int n, m, extra = 0; cin>>n>>m;
    vec<vec<int>> sets(n);
    vec<int> reps(m+1);
    int l, s;
    for (int i = 0; i < n; i++) {
        cin>>l;
        for (int j = 0; j < l; j++) {
            cin>>s;
            sets[i].push_back(s);
            reps[s]++;
        }
    }
    for (int i = 1; i < m+1; i++) {
        if(!reps[i]){
            return void(cout<<"NO"<<endl);
        }
    }
    bool f;
    bool good = 0;
    for(auto &e:sets){
        f = 1;
        for(auto &i:e){
            if(reps[i]<2){
                f = 0;
                break;
            }
        }
        if(f){
            if(good)return void(cout<<"YES"<<endl);
            good = 1;
        }
    }
    cout<<"NO"<<endl;

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


