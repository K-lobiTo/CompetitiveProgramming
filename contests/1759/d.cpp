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
    ll n, m;
    cin>>n>>m;
    map<ll, int> fact;
    ll nf = n;
    while(n>0 && !(nf%2)){
        fact[2]++;
        nf/=2;
    }
    while(n>0 && !(nf%5)){
        fact[5]++;
        nf/=5;
    }
    ll k = 1;
    while(fact[2] < fact[5]){
        if(k*2 > m){
            break;
        }
        else{
            k*=2;
            fact[2]++;
        }
    }
    while(fact[5] < fact[2]){
        if(k*5 > m){
            break;
        }
        else{
            k*=5;
            fact[5]++;
        }

    }
    while(k*10 <= m){
        k*=10;
    }
    if(k==1) return void(cout<<n*m<<endl);
    k*= m/k;
    cout<<n*k<<endl;
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  
