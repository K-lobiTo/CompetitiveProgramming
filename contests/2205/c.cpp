#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<vec<int>> b(n);
    for (int i = 0; i < n; i++) {
        int size; cin>>size;
        set<int> in;
        for (int j = 0; j < size; j++) {
            int v; cin>>v;
            if(!in.contains(v))b[i].push_back(v);
            in.insert(v);
        }
    }
 
    set<int> in;
    vec<int> ans;
    int d = 0;
    while(d<n){
        ranges::sort(b, [&](vec<int> f, vec<int> s) -> bool{
                if(f.empty())return 1;
                if(s.empty())return 0;
                int fs = f.size();
                int ss = s.size();
                for (int i = 0; i < min(fs, ss); i++) {
                    if(f[fs-i-1] < s[ss-i-1])return 1;
                    if(f[fs-i-1] > s[ss-i-1])return 0;
                }
                return f.size() > s.size();
                });
        // int idx = 0;
        // for(auto &l:b){
        //     DEBUG(idx++); 
        //     for(auto &e:l)cout<<e<<" ";
        //     cout<<endl;
        // }

        while(d<n && b[d].empty())d++;
        if(d>=n)break;

        for (int j = (int)b[d].size() - 1; j >= 0; j--) {
            if(in.contains(b[d][j]))continue;
            ans.push_back(b[d][j]);
            in.insert(b[d][j]);

            for (int m = d+1; m < (int)b.size(); m++) {
                while(b[m].size() && in.contains(b[m].back()))b[m].pop_back();
            }
        }

        while(b[d].size())b[d].pop_back();
        d++;
    }
    for(auto &e:ans)cout<<e<<" ";
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


