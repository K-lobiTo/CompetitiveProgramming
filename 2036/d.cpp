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
    int n, m, count = 0, len;
    string ans = "1543", act;
    cin>>n>>m;
    vec<char> lay;
    char mat[n][m];
    for(int i=0;i<n;i++)for(int j=0;j<m;j++)cin>>mat[i][j];
    for(int gap = 0; gap<n/2 && gap<m/2; ++gap){
        lay.clear();
        for(int i=gap  ;i<(m-gap);++i)lay.push_back(mat[gap][i]);
        for(int i=gap+1;i<(n-gap);++i)lay.push_back(mat[i][m-gap-1]);  //lr left-right
        for(int i=gap+1;i<(m-gap);++i)lay.push_back(mat[n-gap-1][m-i-1]);//ud up-down
        for(int i=gap+1;i<(n-gap-1);++i)lay.push_back(mat[n-i-1][gap]);
        len = lay.size();
        for(int i = 0; i<len;++i){
            act="";
            act+=lay[i];
            act+=lay[(i+1)%len];
            act+=lay[(i+2)%len];
            act+=lay[(i+3)%len];
            // DEBUG(act);
            count+=(act==ans);
        }
    }
    cout<<count<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  