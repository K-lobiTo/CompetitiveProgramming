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
  
bool solve(){
    int n, k;cin>>n>>k; 
    string s;cin>>s;
    if(n==1)return false;
    for(int i = 0; i<(n/2);++i){
        if(s[i]<s[n-i-1])return true;
    }
    string s2 = s;
    reverse(ALL(s2));
    for(int i = 0; i<(n-1);++i){
        if(s[i]>=s2[i]){
        for(int j = 1+1; j<n;++j){
        }
    }
    }
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<(solve()? "YES\n":"NO\n");
}return 0;
}
  