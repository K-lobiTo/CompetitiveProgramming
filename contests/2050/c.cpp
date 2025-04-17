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
  
bool ans(ll act, int threes, int twos){
    if(!(act%9))return true;

    bool subAns3 = false;
    if(threes) subAns3 = ans(act+6, threes-1,twos);
    if(subAns3)return true;

    bool subAns2 = false;
    if(twos) subAns2 = ans(act+2, threes,twos-1);
    if(subAns2)return true;

    return false;
}

bool solve(){
    string n;
    ll sum = 0;
    ll two = 0;
    ll three = 0;
    cin>>n;
    for(char c:n){
        sum+=c-'0';
        if((c-'0') == 2)two++;
        else if((c-'0') == 3)three++;
    }
    return ans(sum, min(8LL, three), min(8LL, two));
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<(solve()? "YES\n" : "NO\n");
}return 0;
}
  