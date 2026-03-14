#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    map<int, int> cds;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int inp; cin>>inp;
            cds[inp]++;
        }
    }
    for(auto &[v, c]:cds){
        if(c > ((n-1)*n))return void(cout<<"No"<<endl);
    }
    cout<<"Yes"<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


