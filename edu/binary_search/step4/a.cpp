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
const long double ERR = 1e-6;
int t=1;
int n, d;
vec<int> a;
int idxi = 1, idxj = 1;

bool ok(long double x){
    vec<long double> p(n+1, 0);
    for (ll i = 1; i < n+1; i++) {
        p[i] = (long double)a[i-1] - i*x;
    }
    // for(auto &e:p)cout<<e<<' ';
    // cout<<endl;
    vec<long double> mins(n, (long double)1e9);
    mins[0] = p[0];
    vec<int> minIdx = {1};
    for (ll i = 1; i < n; i++) {
        mins[i] = min(mins[i-1], p[i]);
        if(mins[i]<mins[i-1])minIdx.push_back(i+1);
        else minIdx.push_back(minIdx.back());
    }
    // for(auto &e:mins)cout<<e<<' ';
    // cout<<endl;
    for (ll i = n; i >= d; i--) {
        if(p[i]>=mins[i-d]){
            idxi = minIdx[i-d];
            idxj = i;
            return true;
        }
    } 
    return false;
}
  
void solve(){
    cin>>n>>d;
    a.resize(n);
    rAuto(a);
    partial_sum(ALL(a), a.begin());
    long double l = 0;
    long double r = (long double)1e9;
    // DEBUG(ok(50));
    while(l+ERR < r){
        long double mid = (l+r)/2;
        if(ok(mid))l = mid;
        else r = mid;
    }
    // cout<<l<<endl;
    // DEBUG(l);
    cout<<idxi<<' '<<idxj<<endl;
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


