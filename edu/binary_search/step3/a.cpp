#include <bits/stdc++.h>
#include <iomanip>
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
const long double ERR = 1e-9;
int t=1;
int n;
vec<ll> xi;
vec<ll> vi;
bool ok(long double T){
    long double mini = 1e9;
    long double maxi = -1e9;
    for (int i = 0; i < n; i++) {
        mini = min(mini, xi[i] + T*vi[i]);
        maxi = max(maxi, xi[i] - T*vi[i]);
    }
    return (mini-maxi) >=0;
}
 
void solve(){
    cin>>n;
    xi.resize(n);
    vi.resize(n);
    for (int i = 0; i < n; i++) {
        cin>>xi[i];
        cin>>vi[i];
    }
    long double l = 0;
    long double r = 1;while(!ok(r))r*=2;
    // DEBUG(r);
    while (l+ERR < r) {
        long double mid = (l+r)/2;
        if(ok(mid))r = mid;
        else{
            l = mid;
        }
    }
    cout<<r<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout<<setprecision(20);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


