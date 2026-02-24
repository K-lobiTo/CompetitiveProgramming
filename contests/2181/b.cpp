#include <bits/stdc++.h>
#include <queue>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, m; cin>>n>>m;
    priority_queue<ll> a, b;
    ll val;
    for (int i = 0; i < n; i++) {
        cin>>val;
        a.push(val);
    }
    for (int i = 0; i < m; i++) {
        cin>>val;
        b.push(val);
    }

    bool turn = 1;
    while(!a.empty() && !b.empty()){
        if(turn){
            // DEBUG("aliceTurn");
            val = b.top();
            // DEBUG(val);
            b.pop();
            if(val > a.top())b.push(val-a.top());
        }
        else{
            // DEBUG("bobTurn");
            val = a.top();
            // DEBUG(val);
            a.pop();
            if(val > b.top())a.push(val-b.top());
        }
        turn = !turn;
    }

    if(a.empty())cout<<"Bob"<<endl;
    else cout<<"Alice"<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


