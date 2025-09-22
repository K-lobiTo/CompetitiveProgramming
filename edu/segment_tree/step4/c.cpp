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
const ll MAXA = 41;
int t=1;

struct Mono {
    ll invs;
    ll reps[MAXA];
    Mono(){
        invs = 0;
        for (int i = 0; i < MAXA; i++) {
            reps[i] = 0;
        }
    }
    Mono(ll v){
        invs = 0;
        assert(v<MAXA);
        assert(v>=1);
        for (int i = 0; i < MAXA; i++) {
            reps[i] = (i == (v-1));
        }
    }
};

Mono operator+(const Mono& a, const Mono& b) {
    Mono res;
    res.invs = a.invs + b.invs;
    
    for (int i = 0; i < MAXA; i++) {
        res.reps[i] = a.reps[i] + b.reps[i];
    }
    
    ll sum = 0;
    for (int r = 0; r < MAXA; r++) {
        res.invs += a.reps[r] * sum;
        sum += b.reps[r];
    }
    
    return res;
}

struct SegmentTree {
  int n;
  vector<Mono> s;

  SegmentTree(int n) : n(n), s(n<<1) {}
  SegmentTree(vector<Mono> const& a) : n(a.size()), s(a.size()<<1) {
    copy(ALL(a), s.begin() + n);
    for (int i = n - 1; i > 0; --i) s[i] = s[i<<1] + s[i<<1|1];
  }

  void set(int x, Mono m) {
    for (s[x += n] = m; x >>= 1;) s[x] = s[x<<1] + s[x<<1|1];
  }

  Mono get(int l, int r) { // [l, r)
    Mono resl, resr;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) resl = resl + s[l++];
      if (r&1) resr = s[--r] + resr;
    }
    return resl + resr;
  }
};
  
void solve(){
    int n, q; cin>>n>>q;
    vec<Mono> a; 
    int inp;
    for (int i = 0; i < n; i++) {
        cin>>inp;
        a.push_back(Mono(inp));
    }
    SegmentTree sgt(a);
    int ty, x, y;
    while(q--){
        cin>>ty>>x>>y;
        x--;
        if(ty-1){
            sgt.set(x, Mono(y));
        }
        else{
            cout<<sgt.get(x, y).invs<<endl;
        }
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


