#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n, k, p, m; cin>>n>>k>>p>>m;
    queue<int> deck;
    int pVal = -1;
    for (int i = 0; i < n; i++) {
        int inp; cin>>inp;
        deck.push(inp);
        if(i == p-1)pVal = inp;
    }
    multiset<int> firKs;
    while(deck.size()> n-k){
        firKs.insert(deck.front());deck.pop();
    }
    // DEBUG(firKs.size());
    // DEBUG(pVal);
    int ans = 0;
    while(m>0){
        if(p <= k){
            if(m<pVal)break;
            ans++;
            deck.push(pVal);
            firKs.erase(firKs.find(pVal));
            firKs.insert(deck.front()); deck.pop();
            p = n;
            m-=pVal;
        }
        else {
            auto minv = firKs.begin();
            if(*minv > m)break;
            m-=*minv;

            deck.push(*minv);
            firKs.erase(minv);
            firKs.insert(deck.front()); deck.pop();
            p--;
        }
        // DEBUG(firKs.size());
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


