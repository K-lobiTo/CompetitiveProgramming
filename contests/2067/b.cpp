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
    int n;cin>>n;
    int input;
    vec<int> a(n+1, 0);
    for(int i = 0; i<n; ++i){
        cin>>input;
        a[input]++;
    }
    for(int i = 0; i<n; ++i){
        if(a[i]%2){
            if(a[i]<2)return false;
        }
        if(a[i]>2)a[i+1]+=a[i]-2;
    }
    return true;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<(solve()? "Yes\n" : "No\n");
}return 0;
}
  