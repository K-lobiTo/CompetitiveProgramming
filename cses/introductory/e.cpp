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
    int n;cin>>n; 
    if(n==1){
    cout<<"1\n";
    return;
    }
    if(n<4){
    cout<<"NO SOLUTION\n";
    return;
    }
    vec<int> ans;
    for(int i = 1; i< n; i+=2)ans.push_back(i+1);
    for(int i = 0; i< n; i+=2)ans.push_back(i+1);
    for(auto &e: ans)cout<<e<<' ';
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
  