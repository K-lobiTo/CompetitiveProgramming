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

vec<ll> prefixsumA;
vec<ll> prefixsumB;

bool ok(ld m){
    ld cmax = -1e8;
    for (int i = 0; i < prefixsumA.size(); i++) {
        cmax = max(cmax, prefixsumA[i] - m*prefixsumB[i]);
    }
    return cmax>0;
}
  
void solve(){
    cin>>n>>k;
    vec<pair<int, int>> input(n);
    for(auto &e:input){
        cin>>e.first>>e.second;
    }
    sort(ALL(input), [](pair<int, int> &p1, pair<int, int> &p2){
            if(p1.second != p2.second)return p1.second < p2.second;
            return p1.first < p2.first;
            });

    // for (int i = 0; i < n; i++) {
    //     cout<<"a: "<<input[i].first<<" b: "<<input[i].second<<endl;
    // }

    ll acum = 0;
    for (int i = 0; i < n; i++) {
       acum += input[i].first; 
       if((i+1)>=k){
           prefixsumA.push_back(acum);
           acum-=input[i-(k-1)].first;
       }
    }
    acum = 0;
    for (int i = 0; i < n; i++) {
       acum += input[i].second; 
       if((i+1)>=k){
           prefixsumB.push_back(acum);
           acum-=input[i-(k-1)].second;
       }
    }
    // for(auto &e: prefixsumA)cout<<e<< " ";cout<<endl;
    // for(auto &e: prefixsumB)cout<<e<< " ";cout<<endl;

    ld l = 0;
    ld r = 2; while(ok(r))r*=2;

    ld ERR = 1e-7;
    while(l+ERR < r){
        ld mid = (l+r)/2;
        if(ok(mid))l = mid;
        else r = mid;
    }
    cout<<l<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    cout<<setprecision(20);
    while(t--){
        solve();
    }
    return 0;
}


