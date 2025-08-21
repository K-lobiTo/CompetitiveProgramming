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
#define ld long double
const int MAX = 1e8, MOD = 1e9+7;
int t=1;
int n, m; 
vec<vec<pair<int, int>>> ad;
vec<int> topoSort;


std::vector<int> topologicalSort(int numVertices, const std::vector<std::vector<int>>& adj) { 
    std::vector<int> inDegree(numVertices, 0);
    for (int i = 0; i < numVertices; ++i) {
        for (int neighbor : adj[i]) {
            inDegree[neighbor]++;
        }
    }

    std::queue<int> q;
    for (int i = 0; i < numVertices; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    std::vector<int> topoOrder;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topoOrder.push_back(u);

        for (int v : adj[u]) {
            inDegree[v]--;
            if (inDegree[v] == 0) {
                q.push(v);
            }
        }
    }
    return topoOrder;
}

bool ok(ld med, vec<int> &path, bool wantPath){
    vec<pair<int, ld>> dp(n, {-1, MAX});
    dp[0].second = 0;
    for(auto &e : topoSort){
        for(auto &[child, cost] : ad[e]){
            ld newCost = dp[e].second + cost - med;
            if(newCost < dp[child].second) dp[child] = {e, newCost};
        }
    }
    if(wantPath){
        int node = n-1;
        path.push_back(n-1);
        while(node>0){
            path.push_back(dp[node].first);
            node = dp[node].first;
        }
    }
    return dp[n-1].second <= 0;
}

void solve(){
    cin>>n>>m; 
    ad.assign(n, vec<pair<int, int>>()); 
    vec<vec<int>> adjtp(n);
    // junctions are going from lower to higher => is DAG
    for (size_t i = 0; i < m; i++) {
        int a, b, c;
        cin>>a>>b>>c; 
        ad[a-1].push_back({b-1, c});
        adjtp[a-1].push_back(b-1);
    }

    topoSort = topologicalSort(n, adjtp);

    vec<int> ans;
    ld l = 0;
    ld r = 2; while(!ok(r, ans, 0))r*=2;
    const ld ERR = 1e-6;
    while(l+ERR < r){
        ld mid = (l+r)/2.0;
        if(ok(mid, ans, 0))r=mid;
        else l=mid;
    }

    ok(r, ans, 1);
    cout<<ans.size()-1<<endl;
    for (int i = ans.size()-1; i>=0; i--) cout<<ans[i]+1<<" ";
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


