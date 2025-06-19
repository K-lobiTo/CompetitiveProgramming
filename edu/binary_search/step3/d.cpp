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
int ok(ll limit, int dcount, int node){
    if(dcount>d)return 0;
    if(node == n-1){
        return dcount;
    }
    int subAns = 0;
    for (int i = 0; i < n; i++) {
        if(!vis[i] && mat[node][i]!=-1 && mat[node][i]<=limit){
            vis[i] = true;
            subAns += ok(limit, dcount+1, i);
            if(subAns) break;
        }
    }
    return subAns;
}
  
vec<int> getPath(ll limit, int size, int node){
    vec<int> Ans;
    if(size<0)return Ans;
    if(node == n-1)return {n-1};
    for (int i = 0; i < n; i++) {
        if(!vis[i] && mat[node][i]!=-1 && mat[node][i]<=limit){
            vis[i] = 1;
            vec<int> sAns = getPath(limit, size-1, i);
            vis[i] = 0;
            if(!sAns.empty()){
                Ans.push_back(i);
                Ans.insert(Ans.end(), ALL(sAns));
                break;
            }
        }
    }
    return Ans;
}

void solve(){
    cin>>n>>m>>d;
    mat.assign(n, vec<ll>(n, -1));
    vis.assign(n, false); vis[0] = true;
    ll a, b, c;
    for (int i = 0; i < m; i++) {
        cin>>a>>b>>c;
        a--;b--;
        mat[a][b] = c;
        mat[b][a] = c;
    }
    // for(auto &row:mat){for(auto &e:row)cout<<e<<' ';cout<<endl;}
    ll l = -1;
    ll r = 1;
    int eCount;
    // vec<int> route;
    while(!ok(r, 0, 0)){
        vis.assign(n, false); vis[0] = true;
        r*=2;
    }
    // DEBUG(r);
    // for(auto &e:route)cout<<e<<' ';
    // cout<<endl;
    while(l+1 < r){
        vis.assign(n, false); vis[0] = true;
        ll mid = (l+r)/2;
        eCount = ok(mid, 0, 0);
        if(eCount)r = mid;
        else l = mid;
    }
    if(!r){
        cout<<-1<<endl;
        return;
    }
    // DEBUG(r);
    cout<<eCount<<endl;
    vec<int> path = getPath(r, eCount, 0);
    cout<<1<<' ';
    for (int i = 0; i < eCount; i++) {
       cout<<path[i]+1<<' ';
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


