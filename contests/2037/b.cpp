
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
    int k;cin>>k;
    vec<int> a(k);
    for(auto&e:a)cin>>e;
    sort(ALL(a));
    for(int i = 0; i<k; ++i){
        int it = lower_bound(a.begin()+i, a.end(), (k-2)/a[i])-a.begin();
        if((a[it]*a[i])==(k-2)){
            cout<<a[it]<<' '<<a[i]<<'\n';
            return;
        }
    }
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  