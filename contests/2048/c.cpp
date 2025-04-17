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
    string s;cin>>s;
    int card = s.size(), l = 1, r = 1;
    cout<<1<<' '<<card<<' ';
    bool done = false;
    int dist = 0;
    int count = 0;
    int f0 = -1;
    for(int i = 1; i<card && !done; ++i){
        if(s[i]=='0'){
            if(!count){
                dist = card-i;
                f0 = i;
                count++;
            }
            else{
                count++;
            }
        }
        else if(count)done = true;
    }
    if(count){
        dist = card-f0;
        l = min(count, f0);
        l = f0 - l +1; 
        r = l+dist-1;
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
  