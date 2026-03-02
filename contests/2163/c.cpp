#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define pii pair<int, int>

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

int n;

void solve(){
    cin>>n;
    vec<vec<int>> a(2, vec<int>(n));
    for(auto &row:a){
        for(auto &col:row)cin>>col;
    }
    vec<vec<pii>> pos(2*n + 1);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            pos[a[i][j]].push_back({i, j});
        }
    }

    vec<set<int>> block(2);
    
    block[0].insert(MAX);
    block[1].insert(-MAX);

    for (int i = 0; i < n; i++) block[0].insert(i), block[1].insert(i);

    auto unblck = [&](int val){
        for(auto &[i, j]:pos[val]){
            block[i].erase(j);
        }
    };

    auto blck = [&](int val){
        for(auto &[i, j]:pos[val]){
            block[i].insert(j);
        }
    };

    auto check = [&]() -> bool{
        if(block[0].count(0))return 0;
        if(block[1].count(n-1))return 0;
        return *block[0].begin()-1 > *block[1].rbegin();
    };


    ll ans = 0;
    ll r = 0;
    for (int l = 1; l <= 2*n ; l++) {
        while(r + 1 <= 2*n && !check()){
            unblck(++r);
        }
        if(!check())break;
        ans+= 2*n - r + 1;
        blck(l);
    }
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


