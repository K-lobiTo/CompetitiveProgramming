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
    vec<ll> a(n);
    rAuto(a);
    int asize = n;
    int it = 0;
    int prev = a[0];
    int count = 1;
    for (int i = 0; i < n; i++) {
        if(a[i] >= prev+2){
            prev = a[i];
            count++;
        }
    }
    // while (it+1<asize) {
    //     if(a[it]== a[it+1]-1 || a[it] == a[it+1]){
    //         a.erase(a.begin()+it+1);
    //         it--;
    //         asize--;
    //     }
    //     it++;
    // }
    // cout<<asize<<endl;
    cout<<count<<endl;
    
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


