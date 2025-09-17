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
  
void solve(){
    int n, k; cin>>n>>k;
    vec<ll> a(n); rAuto(a);
    sort(ALL(a));
    deque<ll> dq(ALL(a));
    vec<ll> b(k); rAuto(b);
    sort(ALL(b)); int cb = 0;
    int toPay = 0;
    ll ans = 0;
    // DEBUG(dq.back());
    // DEBUG(dq.front());
    while(!dq.empty()){
        if(( cb < k ) && ( b[cb] <= dq.size() )){
            toPay = b[cb];
            while(toPay){
                if(toPay == 1){
                    dq.pop_back();
                }
                else {
                    ans+=dq.back();
                    dq.pop_back();
                }
                toPay--;
            }
            cb++;
        }
        else {
            ans+=dq.front();
            dq.pop_front();
        }
    }
    cout<<ans<<endl;

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


