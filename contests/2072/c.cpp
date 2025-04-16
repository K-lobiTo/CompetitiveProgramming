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
    ll n, x;cin>>n>>x; 
    ll ac = 0;
    ll c = 0;
    if(x%2 == 0){
        cout<<x;
        for(int i = 1; i<n; ++i){
            cout<<" 0";
        }
    }
    else{
        for(int i = 0; i<n; ++i){
            if(i == (n-1) && ((ac|i) != x)){
                cout<<x<<' ';
                c++;
            }
            else if((i|x) == x){
                cout<<i<<' ';
                ac|=i;
                c++;
            }
        }
        while(c++ < n)cout<<"0 ";
    }
    
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
  