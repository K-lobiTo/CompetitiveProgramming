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
  
void solve(){
    int n; cin>>n;
    set<pair<int, int>> edges;
    vec<int> vis(n, 0), limitstack;
    vis[0]=1;
    for(int i = 1; i<n; ++i)limitstack.push_back(i);

    int x;
    while (!limitstack.empty()){
        int ls = limitstack.back();
        limitstack.pop_back();
        if(vis[ls])continue;
        int l = 0, r = ls;
        while(!false){
            cout<<"? "<<l+1<<' '<<r+1<<endl;
            cin>>x; x--;
            if(x==l){
                edges.insert({l+1, r+1});
                vis[r] = 1;
                break;
            }
            if(vis[x])l = x;
            else r = x;
        }
        limitstack.push_back(ls);
    }
    cout<<"! ";
    for(auto& [a, b]:edges){
        cout<<a<<' '<<b<<' ';
    }
    cout<<endl;
    
     
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  