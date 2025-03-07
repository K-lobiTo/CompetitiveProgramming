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
    string s, ans = "";
    ll n = 1;
    cin>>s;
    sort(ALL(s));
    ans+=s+'\n';
    while(next_permutation(ALL(s))){
        n++;
        ans+=s+'\n';
    } 
    cout<<n<<'\n';
    cout<<ans;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
while(t--){
solve();
}return 0;
}
  