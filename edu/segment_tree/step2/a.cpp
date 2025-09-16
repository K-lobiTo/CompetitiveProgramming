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

struct Mono {
    ll sum, pref, suf, seg;
    Mono(ll s = 0,ll p=0,ll su=0,ll se=0) : sum(s), pref(p), suf(su), seg(se) {}
};

Mono operator+(Mono a, Mono b) {
    return {
        (a.sum + b.sum), 
        max(a.sum + b.pref, a.pref),
        max(a.suf + b.sum, b.suf),
        max({a.seg, b.seg, a.suf + b.pref})
    };
}

Mono single(ll v){
    return {v, max(0LL,v), max(0LL,v), max(0LL,v)};
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
    int n, m; cin>>n>>m;
    vec<Mono> a(n);
    for (int i = 0; i < n; i++) {
        ll ac; cin>>ac;
        a[i] = single(ac);
    }
    SegmentTree sgt(a);
    cout<<sgt.get(0, n).seg<<endl;
    while(m--){
        ll i, v; cin>>i>>v;
        sgt.set(i, single(v));
        cout<<sgt.get(0, n).seg<<endl;
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


