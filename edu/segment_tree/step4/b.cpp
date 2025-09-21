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
ll r;
  
struct Mono {
    ll mat[2][2];

    Mono(ll a = 1, ll b = 0, ll c = 0, ll d = 1) {
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }
    Mono(ll v[2][2]){
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                mat[i][j] = v[i][j];
            }
        }
    }
};

Mono operator+(Mono a, Mono b) {
    Mono ans(0, 0, 0, 0);
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            for (int j = 0; j < 2; j++) {
                ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j])%r;
            }
        }
    }
    return ans;
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
    int n, m; cin>>r>>n>>m;
    vec<Mono> a(n);
    for (int i = 0; i < n; i++) {
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 2; col++) {
                cin>>a[i].mat[row][col];
            }
        }
    }
    SegmentTree sgt(a);
    int l, r;
    while(m--){
        cin>>l>>r;
        l--;
        Mono subans = sgt.get(l, r);
        for (int row = 0; row < 2; row++) {
            for (int col = 0; col < 2; col++) {
                cout<<subans.mat[row][col]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
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


