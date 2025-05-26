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
    int n, k;cin>>n>>k;
    string a; cin>>a;
    int ceros = 0;
    int ones = 0;
    int g = 0;
    for (int i = 0; i < n; i++) {
        if(a[i] == '1'){
            ones++;
        }
        else ceros++;
    }
    for (int i = 0; i < n/2 && g<k; i++) {
        if(ceros>ones){
            g++;
            ceros-=2;
        }
        else{
            g++;
            ones-=2;
        }
    }
    if(n%2){
        if(ceros>ones){
            ceros--;
        }
        else{
            ones--;
        }
    }
    // DEBUG(g);
    // DEBUG(ones);
    // DEBUG(ceros);
    if(ceros == ones){
        cout<<"YES"<<endl; return;
    } 
    cout<<"NO"<<endl;
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


