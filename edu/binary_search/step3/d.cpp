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
int n, m, d;
vec<pair<int, int>> adj[MAX];
vec<int> parent[MAX];

bool can(int x) {
    vec<int> dist(n+1, -1);
    vec<int> prev(n+1, -1);
    dist[1] = 0;
    
    for (int u = 1; u <= n; u++) {
        if (dist[u] == -1) continue;
        if (dist[u] >= d) continue; 
        
        for (auto &[v, w] : adj[u]) {
            if (w <= x && (dist[v] == -1 || dist[v] > dist[u] + 1)) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
            }
        }
    }
    
    return dist[n] != -1 && dist[n] <= d;
}

void solve() {
    cin >> n >> m >> d;
    
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    
    int l = 0, r = 1e9;
    int ans = -1;
    
    while (l <= r) {
        int mid = (l + r) / 2;
        if (can(mid)) {
            ans = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    
    if (ans == -1) {
        cout << -1 << endl;
        return;
    }
    
    vec<int> dist(n+1, -1);
    vec<int> prev(n+1, -1);
    dist[1] = 0;
    
    for (int u = 1; u <= n; u++) {
        if (dist[u] == -1) continue;
        if (dist[u] >= d) continue;
        
        for (auto &[v, w] : adj[u]) {
            if (w <= ans && (dist[v] == -1 || dist[v] > dist[u] + 1)) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
            }
        }
    }
    
    vec<int> path;
    int cur = n;
    while (cur != -1) {
        path.push_back(cur);
        cur = prev[cur];
    }
    reverse(path.begin(), path.end());
    
    cout << path.size() - 1 << endl;
    for (int node : path) {
        cout << node << " ";
    }
    cout << endl;
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


