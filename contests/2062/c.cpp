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
int n;

  
void solve(){ 
    cin>>n;
    ll maxi = - MAX;
    ll sum = - MAX;
    vec<ll> a(n);
    for(auto &e:a)cin>>e;    
    if(n == 1){
        cout<<a[0]<<endl;
        return;
    }
    ll actSum = accumulate(ALL(a), 0LL);
    maxi = max(maxi, actSum);
    for(int i = 0; i<n; ++i){
        for(int j = 1; j< a.size();++j){
            a[j-1] -= a[j];
        }
        a.pop_back();
        ll actSum = accumulate(ALL(a), 0LL);
        sum=max(actSum, -actSum);
        maxi = max(maxi, sum);
    }

    cout<<maxi<<endl;
    
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  