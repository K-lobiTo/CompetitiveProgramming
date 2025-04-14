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
  
ll solve(){
    int n; cin>>n;
    ll tot = 0;
    ll odds = 0;
    vec<int> a(n);
    
    for(int &e: a){
        cin>>e;
        if(e%2) odds++; 
        tot+=e;
    }
    if(odds == n || !odds){
        return *max_element(ALL(a));
    }
    return (tot-odds+1);
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<solve()<<endl;
}return 0;
}
  