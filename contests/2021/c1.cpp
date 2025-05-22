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
  
bool solve(){
    int n, m, q;cin>>n>>m>>q;
    vec<int> a(n);
    vec<int> b(m);
    rAuto(a);
    rAuto(b);
    set<int> prev;
    int j = 0;
    if(a[0]!=b[0])return false;
    for (int i = 0; i < m; i++) {
        //DEBUG(b[i]);
        //DEBUG(a[j]);
        //DEBUG(prev);
        if(b[i]==a[j])continue;
        if(prev.find(b[i])!=prev.end())continue;
        prev.insert(a[j]);
        j++;
        if(j==n)return false;
        if(b[i]==a[j])continue;
        else return false;
    }
    return true;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve() ? "YA" :"TIDAK")<<endl;
    }
    return 0;
}


