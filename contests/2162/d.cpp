#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    cout<<"1 1 "<<n<<endl;
    cout.flush();
    int a; cin>>a;
    cout<<"2 1 "<<n<<endl;
    cout.flush();
    int b; cin>>b;
    int modif = b - a;

    int l = 0, r = n+1;
    while(l+1 < r){
        int m = (l+r)/2;
        cout<<"1 "<<1<<" "<<m<<endl;
        cout.flush();
        int x; cin>>x;
        cout<<"2 "<<1<<" "<<m<<endl;
        cout.flush();
        int y; cin>>y;
        if(y == x)
            l = m;
        else r = m;
    }

    cout<<"! "<<l+1<<" "<<l+modif<<endl;
    cout.flush();
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


