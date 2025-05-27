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

void dfs(int node, ll sum, vec<vec<int>> &g, vec<ll> &dan, bool isSum, vec<ll> &ans, vec<bool> &vis){
    vis[node] = true;
    if(isSum){
        sum+=dan[node];
        ans[node] = sum;
    }
    else {
        sum-=dan[node];
        if(sum<0)sum = 0;
    }
    for(auto &child:g[node]){
        if(!vis[child])dfs(child, sum, g, dan, !isSum, ans, vis);
    }
}
  
void solve(){
    int n; cin>>n;
    vec<ll> dan(n);
    rAuto(dan);
    vec<vec<int>> g(n);
    ll n1, n2;
    vec<ll> ans(n);
    for (int i = 0; i < n-1; i++) {
        cin>>n1>>n2; 
        g[n1-1].push_back(n2-1);
        g[n2-1].push_back(n1-1);
    }
    vec<bool> vis(n, false);
    dfs(0, 0LL, g, dan, 0, ans, vis); 
    vis.assign(n, false);
    dfs(0, 0LL, g, dan, 1, ans, vis); 
    for(auto &e:ans)cout<<e<<' ';
    cout<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


