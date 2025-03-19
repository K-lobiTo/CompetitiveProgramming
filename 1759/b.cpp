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
    int m, s;
    ll total= 0;
    cin>>m>>s;
    vec<int> known(m);
    for(int i =0;i<m;++i){
        cin>>known[i];
        total+=known[i];
    }
    sort(ALL(known));
    int j = 0;
    int i = 1;
    for(;s>0;++i){
        if(j<m && known[j]==(i))j++;
        else{
            s-=(i);
        }
    }
    while(j<m){
        if(known[j]!=i){
            s = 1;break;}
        else{
            j++; i++;
        }
    }
    if(j<(m-1))s = 1;
    cout<<(s? "NO\n":"YES\n");

    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  