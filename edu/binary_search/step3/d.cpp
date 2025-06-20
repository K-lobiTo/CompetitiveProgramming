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
vec<vec<ll>> mat;
vec<bool> vis;


int bfs(ll limit){
    vis.assign(n, false);
    queue<pair<int, int>> q; 
    q.push({0,0});
    vis[0] = 1;
    int dcount = 0;
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        if(node.first == n-1 && node.second<=d){dcount = node.second;break;}
        for (int i = 0; i < n; i++) {
            if(!vis[i] && mat[node.first][i]!=-1 && mat[node.first][i]<=limit){
                vis[i] = true;
                q.push({i, node.second+1});
            }
        }
    }
    return dcount;
}

vec<int> getPath(ll limit, int size){
    vis.assign(n, false);
    vec<int> parent(n, -1);
    queue<pair<int, int>> q; 
    q.push({0,0});
    vis[0] = 1;
    while(!q.empty()){
        pair<int, int> node = q.front();
        q.pop();
        if(node.first == -1 && node.second<=(size+1)){break;}
        for (int i = 0; i < n; i++) {
            if(!vis[i] && mat[node.first][i] != -1 && mat[node.first][i]<=limit){
                vis[i] = 1;
                parent[i] = node.first;
                q.push({i, node.second+1});
            }
        }
    }
    vec<int> path(size+1);
    int idx = size;
    int node = n-1;
    while(node && node!=-1){
        path[idx--] = node+1;
        node = parent[node];
    }
    path[0] = 1;
    return path;
}

void solve(){
    cin>>n>>m>>d;
    mat.assign(n, vec<ll>(n, -1));
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin>>a>>b>>c;
        a--;b--;
        mat[a][b] = c;
        mat[b][a] = c;
    }
    // for(auto &row:mat){for(auto &e:row)cout<<e<<' ';cout<<endl;}
    ll l = -1;
    ll r = (ll)1e9+1LL;
    int eCount = -1;
    while(l+1 < r){
        vis.assign(n, false); vis[0] = true;
        ll mid = (l+r)/2;
        int isOk = bfs(mid);
        if(isOk){r = mid; eCount = isOk;}
        else l = mid;
    }
    if(eCount==-1){
        cout<<-1<<endl;
        return;
    }
    // DEBUG(r);
    cout<<eCount<<endl;
    vis.assign(n, false); vis[0] = true;
    vec<int> path = getPath(r, eCount);
    for(auto &e:path)cout<<e<<' ';
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


