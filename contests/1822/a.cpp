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
int tt=1;
  
void solve(){
    int n, t, input, late=0, maxPopul = -1, ans = -1;
    cin>>n>>t;
    vec<int> a(n);
    vec<int> b(n);
    for(auto &e : a){
        cin>>input;
        e = input+late;
        late++;
    }
    for(auto &e : b){
        cin>>e;
    }
    for(int i = 0; i<n; i++){
        if(a[i]<=t && b[i]>maxPopul){
            maxPopul=b[i]; ans = i+1;}
    }
    cout<<ans<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>tt;
while(tt--){
solve();
}return 0;
}
  