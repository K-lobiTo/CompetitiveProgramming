#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n;cin>>n;
    vec<int> a(n);
    int lessthan;
    int morethan;
    int maxdiff = 0;
    for(auto &e :a )cin>>e;
    int l = 1, r = 1;
    for(int i = 0;i<n;++i ){
        lessthan = 0;
        morethan = 0;
        for(int j = i+1;j<n; ++j){
            if(a[j]<a[i])lessthan++;
            else if(a[j]>a[i]) morethan++;

            if(maxdiff > morethan - lessthan){
                maxdiff = morethan - lessthan;
                l = i+1; r = j+1;
            }
        }
    }
    cout<<l<<' '<<r<<endl;

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  