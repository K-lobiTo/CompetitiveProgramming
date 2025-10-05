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
  
void solve(){
    int n, m; cin>>n>>m;
    vec<vec<char>> mat(n, vec<char>(m));
    int sI, sJ, fI, fJ;
    vec<pair<int, int>> pos = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    vec<char> dirs = {'U', 'D', 'R', 'L'};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin>>mat[i][j]; 
            if(mat[i][j] == 'A'){
                sI = i;
                sJ = j;
            }
            else if(mat[i][j] == 'B'){
                fI = i;
                fJ = j;
            }
        }
    }
    vec<vec<bool>> vis(n, vec<bool> (m));
    auto ok = [&](int i, int j) -> bool{
        return i>=0 && j>= 0 && i<n && j<m && !vis[i][j] && (mat[i][j] == '.' || mat[i][j] == 'B');
    };
    auto end = [&](int i, int j) -> bool{
        return i==fI && j==fJ;
    };
    queue<pair<int, int>> bfs;
    vec<vec<pair<int, int>>> parent(n, vec<pair<int, int>>(m));
    vec<vec<char>> dir(n, vec<char>(m,' '));
    parent[sI][sJ] = {-1, -1};
    bfs.push({sI, sJ});
    vis[sI][sJ] = 1;
    while(!bfs.empty()){
        auto [x, y] = bfs.front();
        bfs.pop();
        for (int i = 0; i < 4; i++) {
            int nx = x+pos[i].first, ny = y+pos[i].second;
            if(ok(nx, ny)){
                vis[nx][ny] = 1;
                bfs.push({nx, ny});
                dir[nx][ny] = dirs[i];
                parent[nx][ny] = {x, y};
                if(end(nx, ny)){
                    cout<<"YES"<<endl;
                    string route = "";
                    while(nx != sI || ny != sJ){
                        route+=dir[nx][ny];
                        auto &[nnx, nny] = parent[nx][ny];
                        nx = nnx; ny = nny;
                    }
                    reverse(ALL(route));
                    cout<<route.size()<<endl;
                    cout<<route<<endl;
                    return;
                }
            }
        }
    }
    cout<<"NO"<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


