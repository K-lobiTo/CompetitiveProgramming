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
  
int solve(){
    vec<int> ans(5);
    int input;
    for(int i = 0; i<4; ++i){cin>>input; ans[input-1] = 1;}
    for(int i = 0; i<5; ++i)if(!ans[i])return i+1;
    
    return -1;

}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
//    cin>>t;
   while(t--){
      cout<<solve()<<endl;
   }return 0;
}
  