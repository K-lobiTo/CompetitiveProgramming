#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int k,n;cin>>n>>k; 
    vec<ll> ls(n);
    vec<ll> rs(n);
    vec<pair<ll, pair<ll, ll>>> both(n);
    for(auto &e: ls)cin>>e;
    for(auto &e: rs)cin>>e;
    for(int i = 0; i<n; ++i){
        both[i].first = ls[i] + rs[i];
        both[i].second.first = ls[i];
        both[i].second.second= rs[i];
    }
    ll ans = 0;
    vec<ll> rest(n);
    sort(both.rbegin(), both.rend());
    for(int i = 0; i<n; ++i){
        ans+=max(both[i].second.first, both[i].second.second);
        rest[i] = min(both[i].second.first, both[i].second.second);
    }
    sort(rest.rbegin(), rest.rend());
    ans+=accumulate(rest.begin(), rest.begin()+(k-1), 0LL);

    cout<<ans + 1<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  