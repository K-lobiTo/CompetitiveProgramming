
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
    vec<int> a(n);
    vec<int> newA;
    // bool isZero = false;
    for(auto&e:a){
        cin>>e;
        // if(!e)isZero = true;
    }
    vec<pair<int, int>> ans;
    for(int i = n-1; i>=0;--i){
        if(!a[i] && i){
            newA.push_back(1);
            ans.push_back({i,i+1});
            a[i-1] = 1;
            i--;
        }
        else newA.push_back(a[i]);
    }
    // newA.push_back(a.front());
    if(!newA.back()){
        ans.push_back({1, 2});
        newA.pop_back();
    }
    ans.push_back({1, newA.size()});
    cout<< ans.size()<<endl;
    for(auto&[a, b]:ans){
        cout<<a<<' '<<b<<endl;
    }
    
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  