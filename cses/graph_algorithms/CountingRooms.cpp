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
    vec<string> mat(n);
    rAuto(mat);
    vec<vec<bool>> vis(n, vec<bool>(m, 0));
    auto ok = [&](int i, int j) -> bool{
        return i>=0 && i<n && j>=0 && j<m && !vis[i][j] && mat[i][j]=='.';
    };
    int ans = 0;
    vec<pair<int, int>> pos = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(ok(i, j)){
                queue<pair<int, int>> bfs; 
                bfs.push({i, j});
                vis[i][j] = 1;
                ans++;
                while(!bfs.empty()){
                    auto [x, y] = bfs.front();
                    bfs.pop();
                    for(auto &[xx, yy]:pos){
                        int nx = x+xx, ny = y+yy;
                        if(ok(nx, ny)){
                            vis[nx][ny] = 1;
                            bfs.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


