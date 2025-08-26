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

typedef struct mstck{
    vec<ll> s, gcds={0};

    void p(ll v){
        s.push_back(v);
        gcds.push_back(gcd(v, gcds.back()));
    }


    ll top(){
        return gcds.back();
    }

    ll pop(){
        ll v = s.back();
        s.pop_back();
        gcds.pop_back();
        return v;
    }

    ll second(){
        return gcds[gcds.size()-2];
    }

    bool emty(){return s.empty();}

    void transf(mstck &ss){
        while(!ss.emty()) p(ss.pop());
    }
}mstck;
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n); rAuto(a);

    int l = 0, ans = 1e9;
    mstck s1, s2;

    auto ok = [&]() -> bool{
        if(s1.emty())s1.transf(s2);
        return (gcd(s1.second(), s2.top())==1);
    };

    for (int r = 0; r < n; r++) {
        s2.p(a[r]);
        while(ok()){
            s1.pop();
            l++;
        }
        if(gcd(s1.top(), s2.top())==1)ans=min(ans, r-l+1);
    }
    

    cout<<(ans==1e9? -1 : ans)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


