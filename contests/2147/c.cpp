#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    string s; cin>>s;
    vec<int> bunnys;
    vec<int> fixed(n);

    auto isBunny = [&](int idx) -> bool {
        if(idx<0 || idx>=n || fixed[idx])return false;
        return s[idx]=='0';
    };

    auto isGood = [&](int idx) -> bool {
        if(idx<0 || idx>=n || s[idx]=='0')return true;
        return false;
    };

    for (int i = 0; i < n; i++) {
        if(s[i] == '0')bunnys.push_back(i);
    }

    for (int i = 0; i < (int)bunnys.size(); i++) {
        int b = bunnys[i];
        if(isGood(b - 1) || isGood(b + 1) || isBunny(b - 2))continue;
        if(isBunny(b+2)) {
            fixed[b+2] = 1;
            i++;
            continue;
        }
        return void(cout<<"No"<<endl);
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


