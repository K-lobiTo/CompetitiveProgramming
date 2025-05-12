
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

int toIn(char &c){
    return c-'0';
}
  
void solve(){
    string s;cin>>s;
    int length = s.size();
    bool flag;
    for(int i = length-1;i>0; --i){
        int j = i;
        flag = 0;
        while(j>0 && (toIn(s[j-1]) < (toIn(s[j])-1))){
            flag = 1;
            char temp = s[j-1];
            s[j-1] = s[j]-1;
            s[j]= temp;
            j--;
        }
        if(flag){
            if(i<(length-1))i++;
            i++;
        }
    }
    cout<<s<<endl;
    
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  