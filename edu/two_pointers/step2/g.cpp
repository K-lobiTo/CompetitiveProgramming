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

template<typename T, T (*op)(T, T)>
class SparseTable {
private:
    vector<vector<T>> st;
    vector<int> log_table;
    int n;
    
public:
    SparseTable(const vector<T>& arr) : n(arr.size()) {
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }
        
        int k = log_table[n] + 1;
        st.resize(n, vector<T>(k));
        
        for (int i = 0; i < n; i++) {
            st[i][0] = arr[i];
        }
        
        for (int j = 1; j < k; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            }
        }
    }
    
    T query(int l, int r) {
        int j = log_table[r - l + 1];
        return op(st[l][j], st[r - (1 << j) + 1][j]);
    }
};

namespace SparseTableOps {
    ll gcd_op(ll a, ll b) { return gcd(a, b); }
}
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n); rAuto(a);

    SparseTable<ll, SparseTableOps::gcd_op> st(a);

    int ans = 1e9;
    for (int l = 0; l < n; l++) {
        int low = l, high = n-1;
        while(low <= high){
            int mid = (low + high)/2;
            if(st.query(l, mid) == 1){
                ans = min(ans, mid-l+1);
                high = mid-1;
            }
            else low = mid + 1;
        }
    }
    cout<<(ans == 1e9 ? -1 : ans)<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


