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

  SegmentTree(int size) {
      n = 1;
      while(n < size)n<<=1;
      s.assign(n<<1, Mono());
  }
  SegmentTree(vector<Mono> const& a){
      n = 1;
      while(n < (int)a.size())n<<=1;
      s.resize(n<<1);
      build(a, 0, 0, n);
  }

  void build(vector<Mono> const &a, int x, int lx, int rx){
      if(!(lx + 1 < rx)){
          if(lx < (int) a.size())
              s[x] = a[lx];
          return;
      }
      int mx = (rx + lx)/2;
      build(a, 2*x + 1, lx, mx);
      build(a, 2*x + 2, mx, rx);
      s[x] = s[2*x + 1] + s[2*x + 2];
  }

  void set(int idx, Mono m) {
      set(idx, m, 0, 0, n);
  }

  void set(int idx, Mono m, int x, int lx, int rx){
      if(!(lx + 1 < rx)){
          s[x] = m;
          return;
      }
      int mx = (lx + rx)/2;
      if(idx < mx)
          set(idx, m, 2*x + 1, lx, mx);
      else 
          set(idx, m, 2*x + 2, mx, rx);

      s[x] = s[2*x + 1] + s[2*x + 2];
  }

  Mono get(int l, int r) { // [l, r)
    return get(l, r, 0, 0, n);
  }

  Mono get(int l, int r, int x, int lx, int rx){
      if(r <= lx || l >= rx) return Mono(); 
      if(l <= lx && rx <= r) return s[x];
      int mx = (lx + rx)/2;
      Mono lm = get(l, r, 2*x +1, lx , mx);
      Mono rm = get(l, r, 2*x +2, mx , rx);
      return lm + rm;
  }
  int fKr(int k, int x, int lx, int rx){
      if(rx-lx == 1)return lx;
      Mono lm = s[x*2 +1];
      int mx = (rx + lx)/2;
      if(k<lm.value){
          return fKr(k, 2*x+1, lx, mx);
      }
      return fKr(k-lm.value, 2*x+2, mx, rx);
  }

  // k'th from right indexed in 0
  int fKr(int k){return fKr(get(0, n).value - k + 1, 0, 0, n);}

};
  
void solve(){
    int n; cin>>n;
    vec<int> inv(n); rAuto(inv);
    vec<Mono> s(n, Mono(1));
    SegmentTree sgt(s);
    vec<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int ci = sgt.fKr(inv[i]);
        ans[i] = ci+1;
        sgt.set(ci, {0});
    }
    for(auto &e:ans)cout<<e<<' ';
    cout<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


