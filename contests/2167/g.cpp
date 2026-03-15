#include <bits/stdc++.h>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;


struct Mono {
    ll value;
    Mono(ll v = 0) : value(v) {}
};

Mono operator+(Mono a, Mono b) {
    return {max(a.value, b.value)};
}

struct SegmentTree {
  int n;
  vector<Mono> s;

  SegmentTree(int n) : n(n), s(n<<1) {}
  SegmentTree(vector<Mono> const& a) : n(a.size()), s(a.size()<<1) {
      ranges::copy(a, s.begin() + n);
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
    int n; cin>>n;
    ll tot = 0;
    set<int> tonorm;
    vec<int> a(n); for(auto &e:a)cin>>e, tonorm.insert(e);
    vec<int> c(n); for(auto &e:c)cin>>e, tot+=e;
    map<int, int> norm; int it = 0;
    for(auto &e:tonorm)norm[e] = it, it++;
    SegmentTree sgt(it+2);

    for (int i = 0; i < n; i++) {
        ll subans = c[i] + sgt.get(0, norm[a[i]]+1).value;
        sgt.set(norm[a[i]], Mono(subans));
    }

    cout<<tot-sgt.get(0, it+2).value<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


