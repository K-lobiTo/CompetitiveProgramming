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

int popfront(vec<int> &v){
    int ans = v[0];
    v.erase(v.begin());
    return ans;
}
int popback(vec<int> &v){
    int ans = v.back();
    v.pop_back();
    return ans;
}
  
void solve(){
    int n, a, b; cin>>n>>a>>b;
    if (a+b > n || (!a && b) || (!b && a)) {
        cout<<"NO"<<endl;
        return;
    }
    int tie = n-b-a;
    int less = min(a, b);
    int more = max(a, b);
    vec<int> aCards(n);
    vec<int> bCards(n);
    iota(ALL(aCards), 1);
    iota(ALL(bCards), 1);
    vec<pair<int, int>> ans;
    while(tie--){
        ans.push_back({popfront(aCards), popfront(bCards)});
    }
    
    while(less--){
        ans.push_back({popback(aCards), popfront(bCards)});
    }
    while (more--) {
        if(bCards.empty() || (bCards.front() == aCards.front())){
            cout<<"NO"<<endl; return;
        }
        ans.push_back({popfront(aCards), popfront(bCards)});
    }
    cout<<"YES"<<endl;
    if(a<b){
        for( auto &[f, s]: ans)cout<<f<< ' ';
        cout<<endl;
        for( auto &[f, s]: ans)cout<<s<< ' ';
        cout<<endl;
        return;
    }
    for( auto &[f, s]: ans)cout<<s<< ' ';
    cout<<endl;
    for( auto &[f, s]: ans)cout<<f<< ' ';
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


