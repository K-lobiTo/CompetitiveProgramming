
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
    bool done = false;
    vec<ll> b(n-1);
    // vec<ll> ans;
    for(auto &e: b)cin>>e;
    vec<ll> original(ALL(b));

    for(int i =0; i<( n-2 ) && !done; ++i){
        if(b[i]<b[i+1]){
            b.insert(b.begin()+i, 0);
            done = true;
        }
    }
    if(!done)b.push_back(0);
    for(int i =(n-1); i>0 ; --i){
        if(max(b[i-1],b[i]) != original[i-1])b[i-1]=original[i-1];
    }

    
    for(auto &e: b){
        cout<<e<<' ';
    }cout<<'\n';
    // DEBUG(n-1);
    // DEBUG(b.size());
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  