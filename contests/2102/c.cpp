
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
    vec<vec<ll>> mat(n+2, vec<ll>(n+2, 0));
    int act = (n*n -1);
    for(int i = 0; i<n+2; i++){
        mat[0][i] = 1;
        mat[n+1][i] = 1;
    }
    for(int i = 0; i<n+2; i++){
        mat[i][0] = 1;
        mat[i][n+1] = 1;
    }
    int i = 1, j = 1;
    vec<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int modDir = 0;
    while (act>0){
        mat[i][j] = act--;
        if(mat[i+directions[modDir].first][j+directions[modDir].second]){
            modDir++;
            modDir%=4;
        }
        i+=directions[modDir].first;
        j+=directions[modDir].second;
    }
    

    for(int i = 1; i<n+1; i++){
        for(int j = 1; j<n+1; j++){
            cout<<mat[i][j]<<' ';
        }
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
  