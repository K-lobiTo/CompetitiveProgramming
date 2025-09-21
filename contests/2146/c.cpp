#include <algorithm>
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
    int n; cin>>n;
    string s; cin>>s;
    deque<int> reserv;
    vec<int> ans(n);
    for (int i = 1; i < n+1; i++) {
        if(s[i-1]=='1')reserv.push_back(i);
    }
    set<int> vls;
    for (int i = 1; i < n+1; i++){
        if(s[i-1]=='0')vls.insert(i);
    }

    reserv.push_back(1e9);

    for (int i = 0; i < n; i++) {
        if(i+1 == reserv.front()){
            ans[i] = reserv.front(); reserv.pop_front();
            continue;
        }
        auto c = vls.lower_bound(reserv.front());
        if(c!=vls.begin())c--;
        if(*c == i+1){
            if(c == vls.begin())return void(cout<<"NO"<<endl);
            c--;
        }
        ans[i] = *c;
        vls.erase(c);

    }
    cout<<"YES"<<endl;
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


