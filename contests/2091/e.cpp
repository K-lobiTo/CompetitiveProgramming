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
int const maxN = 10000001;
vec<int> criba(maxN + 1, 0);
vec<ll> ans(maxN + 1, 0);

void precalc(){
    for(int i = 2; i<maxN; ++i){
        if(!criba[i]){
            for(int j = i; j<maxN; j+=i){
                criba[j]++;
            }
        }
    }
    partial_sum(ALL(criba), ans.begin());
}
  
void solve(){
    int n;cin>>n; 
    // for(int i = 0; i< 15; ++i)cout<<criba[i]<<' ';
    // cout<<endl;
    cout<<ans[n]<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
precalc();
cin>>t;
while(t--){
solve();
}return 0;
}
  