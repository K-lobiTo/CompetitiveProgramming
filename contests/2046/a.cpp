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
int n;

void solve(){
    cin>>n;
    vec<vec<ll>> a(2, vec<ll>(n));

    for(ll &e: a[0])cin>>e;
    for(ll &e: a[1])cin>>e;
    ll maxi =0;
    int ismaxmin = - MAX;
    for(int i = 0; i<n; ++i){
        ismaxmin = max((ll)ismaxmin , min(a[0][i],a[1][i]));
        maxi+=max(a[0][i],a[1][i]);
    }
    
    cout<<maxi+ismaxmin<<endl;

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  