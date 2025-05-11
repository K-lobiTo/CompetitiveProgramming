
#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define rAuto(arr) for(auto &e:arr)cin>>e
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
    if(n==1){cout<<0<<endl;return;}
    vec<vec<ll>> mat(n, vec<ll>(n));
    int act = 4;
    int i = 0, j = 0;
    int st = (!(n%2))? n/2 -1 : n/2;
    mat[st][st] = 0;
    mat[st+1][st] = 2;
    mat[st][st+1] = 1;
    mat[st+1][st+1] = 3;
    int lle = st-1, lra = min(st+2, n-1);
    while(n>2){
        if(act>(n*n -1))break;
        for(int col = lra-1; col>=lle; col--){
            mat[lle][col] = act++;
        }
        if(act>(n*n -1))break;
        for(int row = lle+1; row<=lra; row++){
            mat[row][lle] = act++;
        }
        if(act>(n*n -1))break;
        for(int col = lle+1; col<=lra; col++){
            mat[lra][col] = act++;
        }
        if(act>(n*n -1))break;
        for(int row = lra-1; row>=lle; row--){
            mat[row][lra] = act++;
        }
        if(act>(n*n -1))break;
        lle--;lra++;
    }
    for(auto &row : mat){
        for(auto &e : row)cout<<e<<' ';
        cout<<endl;
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
  