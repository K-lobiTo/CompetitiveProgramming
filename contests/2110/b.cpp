#include <bits/stdc++.h>
#include <numeric>
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
    string s;
    cin>>s;
    int ssize = s.size();
    if(ssize == 2)return true;
    vec<int> a(1);
    for (size_t i = 0; i < ssize; i++) {
        if(s[i]=='(')a.push_back(1);
        else a.push_back(-1);
    }
    partial_sum(ALL(a), a.begin());
    for (size_t i = 1; i < a.size()-1; i++) {
        if(a[i-1] && !a[i] && a[i+1]){
            // DEBUG(i);
            return false;
        }
    }
    // for(auto &e:a)cout<<e<<' ';
    // cout<<endl;
    return true;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cout<<(solve()? "NO" : "YES")<<endl;;
    }
    return 0;
}


