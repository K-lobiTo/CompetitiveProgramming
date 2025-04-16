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
    int n, m;cin>>n>>m;
    vec<vec<ll>> arrs(n, vec<ll>(m)); 

    priority_queue<ll> ans;

    for(auto &row :arrs)for(auto &e: row)cin>>e;
    for(auto &row : arrs){
        ans.push(accumulate(ALL(row), 0LL));
    }
    ll sum = 0;
    for(int i = 0; i< n-1; ++i){
        sum+= ans.top() * m * (n-i-1);
        ans.pop();
    }
    for(auto &row : arrs){
        for(int i = 0; i<m; ++i){
            sum+=row[i]*(m-i);
        }
    }
    cout<<sum<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  