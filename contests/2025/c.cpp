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
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

void solve(){
    int k, n; cin>>n>>k;
    map<ll, int> om;
    ll input; 
    for(int i = 0; i<n; ++i){
        cin>>input;
        om[input]++;
    }

    int ans = 0;
    int subans = 0;
    int myk = 0;
    for(auto &[v, c]: om){
        myk++;
        if(om[v-1]){
            subans+=c;
            if(myk > k){
                myk--;
                subans-=om[v-k];
            }
        }
        else {
            subans=c;
            myk = 1;
        }
        ans = max(ans, subans);
    }
    cout<<ans<<endl;

}
  
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        solve();
    }return 0;
}

