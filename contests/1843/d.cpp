#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

ll leafs(vec<vec<int>> &tree, vec<bool> &vis, vec<ll> &dp, int vertex){
    vis[vertex] = true;
    bool thisIsLeaf = true;
    ll subAns = 0;
    for(auto& child: tree[vertex]){
        if(!vis[child]){
            thisIsLeaf=false;
            subAns+=leafs(tree, vis, dp, child);
        }
    }
    if(thisIsLeaf)return dp[vertex]=1LL;
    dp[vertex] = subAns;
    return subAns;
}

void solve(){
    int u, v, q, x, y, n;
    cin>>n; 
    vec<vec<int>> tree(n);
    for(int i = 0; i< (n-1); ++i){
        cin>>u>>v;u--;v--;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    cin>>q;
    vec<ll> dp(n, 0);
    vec<bool> vis(n, false);
    leafs(tree, vis, dp, 0);
    for(int i = 0; i< q; ++i){
        cin>>x>>y; x--;y--;
        cout<<dp[x]*dp[y]<<'\n';
    }
    // for(auto&e:dp)cout<<e<<' ';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  