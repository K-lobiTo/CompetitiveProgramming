#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n); for(auto &e:a)cin>>e;
    string s; cin>>s;
    vec<ll> b(n); b[0] = 1;
    vec<int> ps(n);
    vec<pair<int, int>> prev; prev.push_back({0, 1e9});
    for (int i = 0; i < n-1; i++) {
        if(s[i] == '<'){
            b[i+1] = b[i]+1;
            prev.push_back({i+1, 1e9});
        }
        else if(s[i]=='>'){
            b[i+1] = 1;
            if(b[i]==1){
                while(prev.back().second <= 0)prev.pop_back();
                ps[i+1] = -1;
                ps[prev.back().first]++;
                prev.back().second--;
            }
            else {
                prev.push_back({i+1, b[i]-b[i+1]-1});
            }
        }
        else b[i+1] = b[i];
    }

    ll acc = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        acc+=ps[i];
        b[i]+=acc;
        sum+=a[i]*b[i];
    }
    cout<<sum<<endl;
    for(auto &e:b)cout<<e<<" ";
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


