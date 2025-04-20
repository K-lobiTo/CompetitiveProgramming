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
    int n;cin>>n;
    string s;cin>>s;
    vec<int> elem(n);
    iota(ALL(elem), 1);
    vec<int> ans;
    for(int i = (n-2); i>=0; --i){
        if(s[i] == '>'){
            ans.push_back(elem.back());
            elem.pop_back();
        }
        else{
            ans.push_back(elem.front());
            elem.erase(elem.begin());
        }
    }
    ans.push_back(elem[0]);
    for(int i = (n-1); i>=0; --i)cout<<ans[i]<<' ';
    cout<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  