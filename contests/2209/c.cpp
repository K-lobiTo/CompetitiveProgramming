#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;

    auto qry = [](int a, int b)->bool{
        int inp;
        cout<<"? "<<a<<" "<<b<<endl;
        cin>>inp;
        return inp;
    };

    bool res;
    for (int i = 1; i+1 < 2*n; i+=2) {
        res = qry(i, i+1);
        if(res)return void(cout<<"! "<<i<<endl);
    }
    res = qry(2*n-2, 2*n-1);
    if(res)return void(cout<<"! "<<2*n-1<<endl);
    res = qry(2*n-3, 2*n-1);
    cout<<"! "<<(res ? 2*n-1 : 2*n)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


