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

string recipe; 
vec<int> BSC(3);
vec<int> nBSC(3);
vec<ll> pBSC(3);
ll r;


  

bool ok(ll x){
    ll mB = max(0LL, x * BSC[0] - nBSC[0]);
    ll mS = max(0LL, x * BSC[1] - nBSC[1]);
    ll mC = max(0LL, x * BSC[2] - nBSC[2]);
    if(( mB*pBSC[0] + mS*pBSC[1] + mC*pBSC[2] ) > r)return false;
    return true;
}

void solve(){

    cin>>recipe;
    rAuto(nBSC);
    rAuto(pBSC);
    cin>>r;

    for(auto &e:recipe){
        if(e == 'B')BSC[0]++;
        else if(e == 'S')BSC[1]++;
        else if(e == 'C')BSC[2]++;
    }
    ll left = 0; //left in ok
    ll right = 1; while(ok(right))right*=2; // right in not ok
    while (left+1<right) {
        ll mid = (left+right)/2;
        if(ok(mid)) left = mid;
        else right = mid;
    }
    cout<<left<<endl;
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


