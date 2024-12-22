
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
    int n, abc[3],goal=0;
    cin>>n>>abc[0]>>abc[1]>>abc[2];

    int s = (abc[0]+abc[1]+abc[2]);
    int i = 0, bot = 0, top = n/s;
    while(bot<=top){
        int mid = (bot + top)/2;
        if(mid * s < n){
            i = mid;
            bot = mid+1;
        }
        else{
            top = mid-1;
        }
    }
    // --i;
    goal+=(i*s);
    int it = 0;
    while(goal+abc[it]<n && (it<3)){
        goal+=abc[it];
        ++it;
    }
    cout<<(3*i)+(it+1)<<'\n';

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  