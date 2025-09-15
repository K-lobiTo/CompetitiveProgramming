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
    ll value;
    Mono(ll v = 0) : value(v) {}
};

Mono operator+(Mono a, Mono b) {
    return {a.value + b.value};
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
        cin>>a[i].value;
    }
    SegmentTree sgt(a);
    while(m--){
        int t, l, r;
        cin>>t>>l>>r;
        if(t==1){
            sgt.set(l, { r });
        }
        else {
            cout<<sgt.get(l, r).value<<endl;
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


