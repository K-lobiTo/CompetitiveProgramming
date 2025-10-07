#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void fin(vec<int> ans){
    cout<<ans.size()<<endl;
    for(auto &e:ans)cout<<e+1<<' ';
    cout<<endl;
    return;

}
  
void solve(){
    int n, m; cin>>n>>m;
    vec<vec<int>> adj(n);
    vec<int> vis(n);
    vec<int> parent(n, -1);
    int a, b;
    for (int i = 0; i < m; i++) {
        cin>>a>>b;a--;b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }


    for (int i = 0; i < n; i++) {
        if(vis[i]) continue;
        stack<int> dfs; dfs.push(i);
        parent[i] = -1;
        while(!dfs.empty()){
            int c = dfs.top(); dfs.pop();
            vis[c] = 1;
            for(auto &e:adj[c]){
                if(e!=parent[c]){
                    if(vis[e]){
                        vec<int> r1; r1.push_back(e);
                        int x = c;
                        bool found = false;
                        while(x!=-1 && !found){
                            r1.push_back(x);
                            if(x == e){
                                found = true;
                            }
                            x = parent[x];
                        }
                        if(found){
                            return void(fin(r1));
                        }
                        set<int> inpath(ALL(r1));
                        vec<int> r2; r2.push_back(e);
                        x = parent[e];
                        while(x!=-1 && !found){
                            r2.push_back(x);
                            if(inpath.count(x)){
                                found = true;
                            }
                            x = parent[x];
                        }
                        while(found){
                            if(r1.back() == r2.back())found = 1;
                            r1.pop_back();
                        }
                        for (int i = r2.size() - 1; i >= 0; i--) {
                            r1.push_back(r2[i]);
                        }
                        return void(fin(r1));
                    }
                    else {
                        parent[e] = c;
                        dfs.push(e);
                    }
                }
            }

        }
    }
    cout<<"IMPOSSIBLE"<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


