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
  
void HAN(int n, int a, int b){
    if(n==1){cout<<a<<' '<<b<<'\n';return;}
    int B=(6-(a+b));
    HAN(n-1, a, B);
    cout<<a<<' '<<b<<'\n';
    HAN(n-1, B, b);

}

void solve(){
    int n; cin>>n;
    cout<<(1<<n)-1<<'\n';
    HAN(n, 1, 3);
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  