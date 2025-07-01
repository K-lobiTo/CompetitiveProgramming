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
    vec<int> a(n);rAuto(a);
    sort(ALL(a));

    vec<int> counts(n+1);
    bool ordered = true;
    int extra = 0;
    int idx = 0;

    for (int i = 0; i < n; i++) {
        if(!ordered) extra++; 
        else if(a[i]-idx >1 || (!i && a[i])){
            ordered = false;
            extra++;
        }
        else if(a[i] == idx){
            extra++;
        }
        counts[a[i]]++;
    }



    // for (int i = 0; i < n+1; i++) {
    //     DEBUG(i);
    //     DEBUG(counts[i]);
    // }
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


