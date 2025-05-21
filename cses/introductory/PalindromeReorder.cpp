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
    string arr;cin>>arr; 
    int n = arr.size();
    map<char,int> chars;
    for(char e : arr){
        if(chars.find(e) == chars.end())chars.insert(make_pair(e, 1));
        else {
            chars[e]++;
        }
    }
    bool valid = true;
    bool existInpair = false;
    for(const auto &[chr, v] : chars){
        if(v%2){
            if(existInpair || !(n%2)){
                valid=false;
                break;
            }
            else {
                existInpair=true;
                arr+=chr; // arr[n] will be the inpair char 
            }
        }
    }
    if(!valid){
        cout<<"NO SOLUTION\n";
        return;
    }
    string ans = "";
    
    if(existInpair){
        string subpalin(chars[arr[n]], arr[n]);
        ans = subpalin;
    } 
    
    for(const auto &[chr, v] : chars){
        if(!(v%2)){
            string subpalin(v/2, chr);
            ans= subpalin+ans+subpalin;
        }
    }
    cout<<ans<<'\n';
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  