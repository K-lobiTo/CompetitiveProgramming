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
const int MAX = int(1e6)+1, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n);rAuto(a);
    int mindist = MAX;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(i!=j && abs(a[i]-a[j])<=1){
                mindist = min(mindist, abs(j-i));
            }
        }
    }
    bool isordered = true;
    for (int i = 0; i < (n-1); i++) {
        if(a[i]>a[i+1]){
            isordered = false;
            break;
        }
    }
    if(isordered && mindist == MAX){
        cout<<-1<<endl;
        return;
    }
    isordered = true;
    for (int i = n - 1; i >= 1; i--) {
        if(a[i]>a[i-1]){
            isordered = false;
            break;
        }
    }
    if(isordered && mindist == MAX){
        cout<<-1<<endl;
        return;
    }
    cout<<min(mindist-1, 1)<<endl;


}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


