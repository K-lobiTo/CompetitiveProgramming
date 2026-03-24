#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

const int SQRD = sqrt(2e5)+1;
  
void solve(){
    int n; cin>>n;
    vec<int> a(n); for(auto &e:a)cin>>e;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] >= SQRD){
            for (int j = 1;i + a[i] * j < n; j++) {
                if(a[i + a[i] * j] == j)ans++;
            }

            for (int j = 1;i - a[i] * j >= 0; j++) {
                if(a[i - a[i] * j] == j)ans++;
            }
        }
        else{
            for (int j = 1;i + a[i] * j < n && j<SQRD; j++) {
                if(a[i + a[i] * j] == j)ans++;
            }
        }
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


