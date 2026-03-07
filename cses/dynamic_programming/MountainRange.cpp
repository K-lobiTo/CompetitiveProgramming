#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long
#define pii pair<int, int>

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

  
void solve(){
    int n; cin>>n;
    vec<pii> h(n);
    for (int i = 0; i < n; i++) {
        int v; cin>>v;
        h[i].first = v; h[i].second = i;
    }

    vec<pii> pge(n+1, {-1e9, -1});
    vec<pii> nge(n+1, {-1e9, -1});
    stack<pii> st;

    for (int i = 1; i <= n; i++) {
        while(st.size()>0 && st.top().first<=h[i-1].first)st.pop();
        if(!st.size())pge[i] = pge[0];
        else pge[i] = st.top();
        st.push(h[i-1]);
        
    }
    while(st.size())st.pop();

    for (int i = n; i > 0; i--) {
        while(st.size()>0 && st.top().first<=h[i-1].first)st.pop();
        if(!st.size())nge[i] = nge[0];
        else nge[i] = st.top();
        st.push(h[i-1]);
    }
    // for(auto &e:pge)cout<<e.first<<" ";
    // cout<<endl;
    // for(auto &e:nge)cout<<e.first<<" ";
    // cout<<endl;

    ranges::sort(h, greater<pii>());

    vec<int> dp(n, 1);
    for (auto [v, i] : h) {

        auto [vl, il] = pge[i+1];
        auto [vr, ir] = nge[i+1];
        if(vl >= v){
            dp[i] = max(dp[i], dp[il] + 1);
        }
        if(vr >= v){
            dp[i] = max(dp[i], dp[ir] + 1);
        }
    }
    // for(auto &e:dp)cout<<e<<" ";
    // cout<<endl;
    cout<<*(ranges::max_element(dp))<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


