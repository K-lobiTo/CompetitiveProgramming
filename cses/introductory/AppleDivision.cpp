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
    int n;cin>>n;
    vec<ll> arr(n);
    ll total=0, subTot=0, ans=LLONG_MAX;
    for(auto&e:arr){
        cin>>e;
        total+=e;
    }
    for(int msk = 0; msk<SET(0, n); ++msk){
        subTot=0;
        for(int j = 0 ; j<n; ++j){
            if(TEST(msk, j))subTot+=arr[j];
        }
        ans=min(ans, abs(2* subTot - total));
    }

    cout<<ans<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  