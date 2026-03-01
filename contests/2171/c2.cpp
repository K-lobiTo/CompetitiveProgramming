#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){
    int n; cin>>n;
    vec<int> a(n), b(n); rAuto(a); rAuto(b);
    unsigned int xorall = 0;
    for (int i = 0; i < n; i++) {
        xorall^=a[i];
        xorall^=b[i];
    }
    if(!xorall)return void(cout<<"Tie"<<endl);
    int msbit = bit_floor(xorall);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(( a[i]^b[i] ) & msbit){
            ans = i+1;
        }
    }
    cout<<(ans&1 ? "Ajisai":"Mai")<<endl;

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


