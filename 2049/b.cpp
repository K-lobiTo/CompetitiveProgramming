
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
    int n;
    bool isS, isP, isDot, ans=true;
    isS = isP = isDot = 0;
    cin>>n;
    string s;
    cin>>s;
    if(s[0]=='s')s[0]='.';
    if(s[n-1]=='p')s[n-1]='.';
    for(int i = 0; i<n; ++i){
        if(s[i]=='s'){
            isS = true;
        }
        else if(s[i]=='p'){
            isP = true;
        }
    }
    cout<<(isS && isP ? "NO\n" : "YES\n");
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  