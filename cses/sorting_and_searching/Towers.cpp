#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

struct setstacks{
    multiset<pair<int, int>> topid;
    vec<stack<int>> stacks;

    void addstack(int v){
        stack<int> ns; ns.push(v);
        stacks.push_back(ns);
        topid.insert({v, stacks.size()-1}); 
    }

    void add(int v){
        auto it = topid.lower_bound({v+1, -1});
        if(it == topid.end())return void(addstack(v));
        int foundid = it->second;
        stacks[foundid].push(v);
        topid.erase(it);
        topid.insert({v, foundid});
    }

    int size(){
        return stacks.size();
    }
};
  
void solve(){
    int n; cin>>n;
    vec<int> a(n);rAuto(a);
    setstacks st;
    for(auto e:a){
        st.add(e);
    }
    cout<<st.size()<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    while(t--){
        solve();
    }
    return 0;
}


