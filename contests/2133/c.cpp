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
    map<int, vec<int>> tS;
    int pos;
    for (int i = 0; i < n; i++) {
        cout<<"? "<<i+1<<" "<<n; 
        for (int j = 0; j < n; j++)
            cout<<" "<<j+1;
        cout<<endl;
        cin>>pos;
        if(pos==-1)exit;
        tS[pos-1].push_back(i+1);
    }
    vec<int> route; route.push_back(tS[tS.size()-1].back());
    for (int i = tS.size() - 2; i >= 0; i--) {
        for(auto &e:tS[i]){
            cout<<"? "<<route.back()<<" 2 "<<e<<" "<<route.back()<<endl; 
            cin>>pos;
            if(pos == -1)exit;
            if(pos==2){
                route.push_back(e);
                break;
            }
        }
    }

    cout<<"! "<<route.size();
    for (int i = 0; i < route.size(); i++) {
        cout<<" "<<route[i];
    }
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    // cin.tie(0); cout.tie(0);
    fflush(stdout);
    cout.flush();
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


