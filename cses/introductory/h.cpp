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
  
ll gauss(ll n){
    if(n<=0)return 0;
    return (n*(n+1))/2;
}

void solve(){
    int n;cin>>n;
    if(gauss(n)%2){cout<<"NO\n";return;}
    vec<vec<int>> ans(2);
    int odd = (n%2);
    for(int i = 1; i<=n/2; ++i){
        ans.at(i%2).push_back(i);
        ans.at(i%2).push_back(n-i+1-odd);
    }
    if(odd)ans.at(0).push_back(n);
    cout<<"YES\n";
    cout<<ans.at(0).size()<<'\n';
    for(auto &e: ans.at(0))cout<<e<<' ';
    cout<<'\n';
    cout<<ans.at(1).size()<<'\n';
    for(auto &e: ans.at(1))cout<<e<<' ';
    cout<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  