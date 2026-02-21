#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
#define ull unsigned long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

const int BTC = 31;
int nCk[BTC][BTC];

void Pascal(){
    for (int i = 0; i < BTC; i++) {
        for (int j = 0; j < BTC; j++) {
            if(i<j)nCk[i][j] = 0;
            else if(!j)nCk[i][j] = 1;
            else nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
        }
    }
}
  
void solve(){
    ll n, k; cin>>n>>k;
    ll ans = 0;
    ll maxBits = log2(n) + 1;
        
    for (int i = 1; i < maxBits; i++) {
        if(i>k)break; // i<=k
        for (int j = 0; (i+j) <= k && j < i; j++) {
            ans+=nCk[i-1][j];
        }
    }
    if(maxBits <= k)ans++;

    cout<<n-ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    Pascal();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


