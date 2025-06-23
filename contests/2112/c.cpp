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
  
void solve(){
    int n; cin>>n;
    vec<int> a(n); rAuto(a);
    sort(ALL(a));
    int blue = a.back();
    a.pop_back();
    n--;
    ll k = 0;
    DEBUG(t);
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if(a[i]+a[j] > blue){
                // DEBUG(i);
                // DEBUG(j);
                k+=n-j;
                break;
            }
        }
    }
    DEBUG(k);
    // DEBUG(a.size());
    // DEBUG(n);
    for (int i = 0; i < n-2; i++) {
        for (int j = i+1; j < n-1; j++) {
            bool over = false;
            for (int m = j+1; m < n; m++) {
                if((a[i] + a[j] + a[m]) > blue){
                    DEBUG(i);
                    DEBUG(j);
                    DEBUG(m);
                    k+=n-m + m-j-1;
                    over = true;
                    break;
                }
            }
            // if(over)break;
        }
    }
    cout<<k<<endl;
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


