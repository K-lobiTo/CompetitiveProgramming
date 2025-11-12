#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n, k; cin>>n>>k;
    vec<vec<int>> a(2, vec<int>(n+1));
    for (int i = 0; i < n; i++) {
        cin>>a[0][i];
    }
    
    set<int> mexx; 
    int mex = 1e9;
    vec<ll> anss;
    for (int i = 0; i < k && i<3; i++) {
        mexx.clear();
        mex = 1e9;
        a[1].assign(n, 0);
        for (int i = 0; i <= n; i++) mexx.insert(i);
            
        for (int i = 0; i < n; i++) {
            a[1][a[0][i]]++;
            auto it = mexx.find(a[0][i]);
            if(it != mexx.end())mexx.erase(it);
        }
        mex = *mexx.begin();

        for (int i = 0; i < n; i++) {
            if(a[0][i]>mex || a[1][a[0][i]] > 1)a[0][i] = mex;
        }
        anss.push_back(accumulate(ALL(a[0]), 0LL));
    }
    if(k<=2){ return void(cout<<anss[k-1]<<endl);}
    cout<<anss[2 - !(k&1)]<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


