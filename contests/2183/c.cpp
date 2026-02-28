#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n, m, k; cin>>n>>m>>k;
    int mid = n/2 + ( n&1 );
    if(k>mid)k = (n-k)+1;
    int l = k, r = k;
    while(1){
        if(l>1 && (( (k-(l-1)) + ((r)-k) + max(k-(l-1), r-k) - 1 ) <= m)){
            l--;
        }
        if(r<n && (( k-l + ((r+1)-k) + max(k-l, (r+1)-k) - 1 ) <= m)){
            r++;
        }
        else break;
    }
    cout<<r-l + 1<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


