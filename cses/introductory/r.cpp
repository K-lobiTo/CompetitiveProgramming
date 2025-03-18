
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
  
ll intervalSum(ll nDigit){
    return nDigit*pow(10, nDigit-1)*9LL;
}

// int nDigits(int k){
//     return floor(log10(k))+1;
// }


void solve(){
    ll k;
    cin>>k;
    // DEBUG(k);
    ll i = 1;
    ll ip10 = 1;
    while (k>intervalSum(i)){
        k-=intervalSum(i);
        ++i;
        ip10*=10;
    }
    ll number = ip10 + (k-1)/i;
    // DEBUG(i);
    // DEBUG(number);
    // DEBUG((k-1)%i);
    cout<<to_string(number)[(k-1)%i]<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
    solve();
}return 0;
}
  