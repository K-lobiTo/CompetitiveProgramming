
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
    string a;
    getline(cin,a);
    string ans = "";
    bool f = true;
    for(int i = 0; i< a.size(); ++i){
        if(a[i] == ' ')f = true;
        else if(f){
            ans+=a[i];
            f = false;
        }
    }
    // DEBUG(ans);
    cout<<ans<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
string nothing;
getline(cin, nothing);
while(t--){
solve();
}return 0;
}
  