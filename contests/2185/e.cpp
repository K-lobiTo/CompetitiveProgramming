#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n, m, k; cin>>n>>m>>k;
    vec<int> a(n), b(m), mvs(1);
    for(auto &e:a)cin>>e;
    for(auto &e:b)cin>>e;
    for (int i = 0; i < k; i++) {
        char c; cin>>c;
        if(c=='R')mvs.push_back(mvs[i]+1);
        else mvs.push_back(mvs[i]-1);
    }

    ranges::sort(a);
    ranges::sort(b);

    vec<multiset<pair<int, int>>> tol(2*k + 1);

    for(auto &e:a){
        int l, r;
        auto lptr = ranges::lower_bound(b, e);
        if(lptr == b.begin())l = -MAX;
        else l = *prev(lptr) - e;
        auto rptr = ranges::upper_bound(b, e);
        if(rptr == b.end())r = MAX;
        else r = *rptr - e;
        
        if(l >= -k)tol[k+l].insert({l, r});
        if(r <= k)tol[k+r].insert({l, r});
        
    }

    vec<int> ans(k);
    int subans = n;
    for (int i = 1; i <= k; i++) {
        if(!tol[k + mvs[i]].empty()){
            while(!tol[k + mvs[i]].empty()){
                subans--;
                auto [l, r]  = *tol[k + mvs[i]].begin();

                if(l >= -k)tol[k + l].erase(tol[k+l].find({l, r}));
                if(r <= k)tol[k + r].erase(tol[k+r].find({l, r}));
            }
        }
        ans[i-1] = subans;
    }

    for(auto &e:ans)cout<<e<<' ';
    cout<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


