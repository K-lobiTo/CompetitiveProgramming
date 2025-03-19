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
  
int solve(){
    ll l, r, x, a, b;
    ll lrdiff = abs(r-l);
    cin>>l>>r>>x>>a>>b;
    if(a>b)swap(a, b);
    if(l<0)r +=abs(l), a+= abs(l), b+= abs(l);
    else r-=l, a-= l, b-= l;
    l = 0;
    if(a==b) return 0;
    if(b-a>=x)return 1;
    if(a >= x || ((r-a >= x) && r-b>=x))return 2;
    if(b < x || r-a < x)return -1;
    return 3;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<solve()<<'\n';
}return 0;
}
  