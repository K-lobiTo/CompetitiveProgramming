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
int n,m,d;
vec<vec<pair<int, int>>> ad;
vec<int> ordered;

std::vector<int> topologicalSort(int n, const std::vector<std::vector<int>>& adj) {
    std::vector<int> inDegree(n, 0);
    for (int i = 0; i < n; ++i) 
        for (int v : adj[i]) inDegree[v]++;
    
    std::queue<int> q;
    for (int i = 0; i < n; ++i) 
        if (inDegree[i] == 0) q.push(i);
    
    std::vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) 
            if (--inDegree[v] == 0) q.push(v);
    }
    return order;
}

bool ok(int x, vec<int> &path, bool wantPath){
    vec<pair<int, pair<int, int>>> dp(n, {1e9, pair<int, int>({-1, 1e9})});
    dp[0].first = 0;
    dp[0].second.second = 0;
    for(auto &e:ordered){
        for(auto &[a, cost]:ad[e]){
            int maxinroute = max(cost, dp[e].first);
            if(dp[e].second.second+1 > d)maxinroute = 1e9+1;
            if(dp[a].first > maxinroute){
                dp[a].first = maxinroute;
                dp[a].second.first = e;
                dp[a].second.second = dp[e].second.second+1;
            }
        }
    }
    if(wantPath){
        int route = n-1;
        while(route>=0){
            path.push_back(route+1);
            route = dp[route].second.first;
        }
    }
    return dp[n-1].first <= x;

}

void solve(){
    cin>>n>>m>>d;
    int a, b, c;
    ad.resize(n);
    vec<vec<int>> toOrder(n);
    for (int i = 0; i < m; i++) {
        cin>>a>>b>>c;
        ad[a-1].push_back({b-1, c});
        toOrder[a-1].push_back(b-1);
    }

    ordered = topologicalSort(n, toOrder);
    

    vec<int> path;
    int l = -1;
    int r = 1e9; // kept ok
    while(l+1 < r){
        int mid = (l+r)/2;
        if(ok(mid, path, 0))r = mid;
        else l = mid;
    }
    // DEBUG(r);
    ok(r, path, 1);
    if(path.size()<2){cout<<-1<<endl; return;}
    cout<<path.size()-1<<endl;
    for (int i = path.size() - 1; i >= 0; i--) {
        cout<<path[i]<<" ";
    }
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


