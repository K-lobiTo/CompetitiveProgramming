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
    int n, m; cin>>n>>m;
    vec<vec<int>> mat(n+1,vec<int>(m+1, 0));
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            cin>>mat[i][j];
        }
    }
    set<int> colors;
    set<int> repcolors;
    ll tot = 0;
    ll maxim = 1;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<m; ++j){
            if(colors.find(mat[i][j]) == colors.end()){
                tot++;
                colors.insert(mat[i][j]);
                if((mat[i+1][j] == mat[i][j]) || (mat[i][j+1] == mat[i][j])){
                    repcolors.insert(mat[i][j]);
                    tot++;
                    maxim = 2;
                }
            }
            else if(repcolors.find(mat[i][j]) == repcolors.end()){
                if((mat[i+1][j] == mat[i][j]) || (mat[i][j+1] == mat[i][j])){
                    repcolors.insert(mat[i][j]);
                    tot++;
                    maxim = 2;
                }
            }
        }
    }
    // if(colors.size() == 1){cout<<0<<endl; return;}
    cout<<tot - maxim<<endl;

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  