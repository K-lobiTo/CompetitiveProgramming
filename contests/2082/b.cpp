
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
    ll x, n, m;
    cin>>x>>n>>m;
    ll n2 = n, m2 = m, x2 = x; 
    while (( n+m ) && x)
    {
        if(( x%2 ) && m){
            m--;
            x = floor((1.0*x)/2);
        }
        else if(n){
            n--;
            x = ceil((1.0*x)/2);
        }
        else{
            m--;
            x = floor((1.0*x)/2);
        }
    }
    while ((n2+m2) && x2)
    {
        if((x2%2) && n2){
            // DEBUG(x2);
            n2--;
            x2 = ceil((1.0*x2)/2);
        }
        else if(m2){
            m2--;
            x2 = floor((1.0*x2)/2);
        }
        else{
            n2--;
            x2 = ceil((1.0*x2)/2);
        }
    }
    cout<<x<<' '<<x2<<'\n';
    
     
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  