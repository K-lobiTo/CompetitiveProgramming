#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n; cin>>n;
    vec<int> arr(n);
    multiset<int> a;
    for(auto &e:arr){
        cin>>e;
        a.insert(e);
    }
    int minval = *a.begin();
    bool opt2 = 1;
    for (int i = 0; i < n; i++) {
        if(gcd(minval, arr[i])!=minval){
            opt2 = 0; break;
        }
    }
    int ansp = 1e9;
    if(opt2){
        ansp = min(ansp, n-(int)a.count(minval));
        return void(cout<<ansp<<endl);
    }
        
    int mn = 1e9;
    int mnidx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int cur = gcd(arr[i], arr[j]);
            if(a.contains(cur))continue;
            if(cur < mn){
                if(arr[i] != cur)mnidx = i;
                else if(arr[j] !=cur) mnidx = j;
                else continue;
                mn = cur;
            }
        }
    }

    int ans = 0;
    if(mnidx != -1){
        a.erase(a.find(arr[mnidx]));
        a.insert(mn);
        // DEBUG(mn);
        ans++;
    }

    // DEBUG(a.count(*a.begin()));
    // for(auto &e:a)cout<<e<<" ";
    // cout<<endl;
    while(!(a.count(*a.begin())==n)){
        int f = *a.begin();
        auto itl = prev(a.end());
        int l = *itl;
        a.erase(itl);
        a.insert(gcd(f, l));

        ans++;
    }

    // DEBUG(mnidx);
    cout<<min(ans, ansp)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


