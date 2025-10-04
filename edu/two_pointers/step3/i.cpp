#include <bits/stdc++.h>
#include <bitset>
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

struct ds {
    vec<ll> values;
    vec<bitset<1001>> sums; 
    
    ds(){
        sums.push_back(bitset<1001>());
        sums.back()[0] = 1;
    }

    ll pop(){
        ll top = values.back();
        sums.pop_back();
        values.pop_back();
        return top;
    }

    void push(ll v){
        values.push_back(v);
        sums.push_back(sums.back() | sums.back()<<v);
    }

    bool empty(){
        return values.empty();
    }

    bitset<1001> getSums(){
        return sums.back();
    }
};

struct segment{
    ds s1, s2;

    void transfer(){
        while(!s1.empty()){
            s2.push(s1.pop());
        }
    }

    void add(ll v){
        s1.push(v);
    }

    void erase(){
        if(s2.empty()) transfer();
        s2.pop();
    }

    bool good(int s){
        // bitset<1001> both;
        // for (int i = 0; i < s+1; i++) {
        //     if(s1.sums.back()[i]) both |= s2.sums.back()<<i;
        //     if(both[s])return 1;
        // }
        for (int i = 0; i < s+1; i++) {
            if(s1.sums.back()[i]){
                if(s2.sums.back()[s-i])return 1;
            }
        }
        return 0;
    }

    void debugboth(int s){
        bitset<1001> both;
        for (int i = 0; i < s+1; i++) {
            if(s1.sums.back()[i]) both |= s2.sums.back()<<i;
        }
        for (int i = 0; i < s+1; i++) {
            cout<<both[i];
        }
        cout<<endl;
    }
};

  
void solve(){
    int n, s; cin>>n>>s;
    vec<int> a(n); rAuto(a);
    int ans = n+1;
    int l = 0;
    segment inseg;
    for (int r = 0; r < n; r++) {
        inseg.add(a[r]);
        while(inseg.good(s)){
            ans = min(ans, r-l+1);
            inseg.erase();
            l++;
        }
    }
    cout<<(ans==n+1?-1:ans)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}
