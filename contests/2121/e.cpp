#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    string l, r; cin>>l>>r;
    string res = r;
    bool aum = 0;
    bool done = 0;
    for (int i = 0; i < res.size(); i++) {
        if(done){
            res[i] = '*';
            continue;
        }
        int dl = l[i]-'0';
        int dr = r[i]-'0';
        if(aum && !dr)dr = 10;
        // DEBUG(dl);
        // DEBUG(dr);
        if(abs(dr - dl) > 1){
            done = 1;
            res[i] = '*';
            continue;
        }
        if(aum && !(l[i] == '9' && r[i]=='0')){
            done = 1;
            res[i] = '*';
            continue;
        }
        if(abs(dr - dl) == 1){
            aum = 1;
            continue;
        }
        assert(l[i] == r[i]);
    }
    int ans = 0;
    for (int i = 0; i < res.size(); i++) {
        ans+= res[i] == l[i];
        ans+= res[i] == r[i];
    }
    // DEBUG(res);
    // cout<<l<<" "<<r<<endl;
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


