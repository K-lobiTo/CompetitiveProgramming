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

template<typename T>
class SparseTable {
private:
    vector<vector<T>> st;
    vector<int> log_table;
    int n;

T op(T a, T b) {
    return max(a, b);
}
    
public:
    SparseTable(const vector<T>& arr) : n(arr.size()) {
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) log_table[i] = log_table[i / 2] + 1;
        
        int k = log_table[n] + 1;
        st.resize(n, vector<T>(k));
        
        for (int i = 0; i < n; i++) st[i][0] = arr[i];
        
        for (int j = 1; j < k; j++)
            for (int i = 0; i + (1 << j) <= n; i++) 
                st[i][j] = op(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
    }
    
    T query(int l, int r) { // [l, r]
        int j = log_table[r - l + 1];
        return op(st[l][j], st[r - (1 << j) + 1][j]);
    }
};
  
void solve(){
    int n, k; cin>>n>>k;
    string s; cin>>s;
    vec<int> ans(n, 0);
    vec<int> tofill(n);
    iota(ALL(tofill), 1);
    int idx = 0;
    int cOnes = 0;
    for (int i = 0; i < n; i++) {
        if(s[i]=='1'){
            ans[i] = tofill[idx];
            idx++;
        }
    }
    for (int i = 0; i < n; i++) {
        while(s[i]=='1' && i<n){
            cOnes++;
            i++;
        }
        if(cOnes>=k){
            cout<<"NO"<<endl;
            return;
        }
        cOnes=0;
    }
    int biggerOne = idx;
    for (int i = 0; i < n; i++) {
        if(!ans[i]){
            ans[i] = tofill[idx];
            idx++;
        }
    }
    SparseTable<int> sp(ans);
    for (int i = 0; i < n-k; i++) {
        if(sp.query(i, i+k-1) <= biggerOne){
            cout<<"NO"<<endl;
            return;

        }
    }
    cout<<"YES"<<endl;
    for(auto &e:ans)cout<<e<<" ";
    cout<<endl;
}

  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


