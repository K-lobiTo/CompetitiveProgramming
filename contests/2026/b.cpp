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
  
void solve(){
    int n; cin>>n;
    priority_queue<ll> pq;
    vec<ll> a(n);rAuto(a);
    if(n==1){
        cout<<1<<endl; return;
    }
    for(int i = 1; i<n; i+=2){
        pq.push(a[i]-a[i-1]);
        if(i==(n-2) && n%2){
            pq.push(a[i+1]-a[i]);
        }
    }
    ll bigger = pq.top(); pq.pop();
    ll compare = pq.top(); pq.pop();
    
    if(!(n&1))
        cout<<bigger<<endl;
    else 
        cout<<compare<<endl;
    
}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  