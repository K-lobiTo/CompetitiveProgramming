#include <bits/stdc++.h>
#include <iomanip>
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
#define ld long double
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
int n, k;
vec<pair<int, int>> input;


bool ok(ld m){
    vec<ld> sorted;
    for (int i = 0; i < n; i++) {
        sorted.push_back(input[i].first - input[i].second * m);
    }
    sort(rALL(sorted));
    ld cmax = accumulate(sorted.begin(), sorted.begin()+k, 0.0);
    return cmax>0;
}
  
void solve(){
    cin>>n>>k;
    input.resize(n);
    for(auto &e:input){
        cin>>e.first>>e.second;
    }

    ld l = 0;
    ld r = 2; while(ok(r))r*=2;

    ld ERR = 1e-7;
    while(l+ERR < r){
        ld mid = (l+r)/2;
        if(ok(mid))l = mid;
        else r = mid;
    }
    cout<<setprecision(12)<<l<<endl;
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


