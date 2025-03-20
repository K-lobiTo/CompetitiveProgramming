
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
    string input;cin>>input; 
    int n = input.size();
    int idx;
    string valid = "Yes";
    if(input[0] == 'Y')idx = 0;
    else if(input[0] == 'e')idx = 1;
    else if (input[0] == 's')idx = 2;
    else {return false;}
    for(int i = 0; i<n; ++i){
        char act = input[i];
        if(act != valid[idx])return false;
        idx= (idx+1)%3;
    }
    return true;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<(solve()?  "YES\n":"NO\n");
}return 0;
}
  