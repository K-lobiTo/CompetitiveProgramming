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
    ll n, m, k;cin>>n>>m>>k;
    ll l = 0; // l is zero because bs ret r
    ll r = m;
    ll mid;
    while ((l+1) < r){
        mid = (l+r)/2;
        if((n*((mid *(m/(mid+1))) + m%(mid+1)))>= k)r = mid;
        else l = mid;
    }
    cout<<r<<endl;
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  