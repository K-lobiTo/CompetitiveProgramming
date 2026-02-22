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

struct pj {
    int a, b;
    ll p;

    pj(int x, int y, ll z): a(x), b(y), p(z) {}
};

struct Mono {
    ll value;
    Mono(ll v = 0) : value(v) {}
};

Mono operator+(Mono a, Mono b) {
    return {max(a.value , b.value)};
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
};
  
void solve(){
    int n; cin>>n;
    vec<pj> pjs;
    set<int> difvalues;
    for (int i = 0; i < n; i++) {
        int a, b, p; cin>>a>>b>>p;
        difvalues.insert(a);
        difvalues.insert(b);
        pjs.push_back(pj(a, b, p));
    }
    map<int, int> norm;
    int idx = 1;

    sort(ALL(pjs), [&](pj f, pj s){
            if(f.b == s.b)return f.a < s.a;
            return f.b < s.b;
            });
    for(auto &e:difvalues) norm[e] = idx++;

    SegmentTree dp(idx+1);
    for(auto &e:pjs){
        int b = norm[e.b];
        int a = norm[e.a];
        ll cur = dp.get(b, b+1).value;
        dp.set(b, Mono(max(cur, e.p +  dp.get(0, a).value)));
    }
    cout<<dp.get(0, idx+1).value<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


