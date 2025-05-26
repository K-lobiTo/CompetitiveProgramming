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

const int L = (int)6e6;
bitset<L> s;
vec<ll> pAcc;

void fillSieve(){
    s.set();
    s[0] = s[1] = 0;
    for (int i = 4; i < L; i+=2) { 
        s[i] = 0;
    }
    for (int p = 3; p*p < L; p++) {
        if(s[p])
            for (int i = p*2; i < L; i+=p) {
                s[i] = 0;
            }
    }

    int count = 0;
    for (int i = 0; i < L && count < (int)4e5; i++) {
        if(s[i]) count++, pAcc.push_back(i);
        // if(count == 400000){cout<<"llega"<<endl;}
    }
    partial_sum(ALL(pAcc), pAcc.begin());
    // for(auto &e:pAcc)cout<<e<<' ';cout<<endl;
}
  
void solve(){
    int n; cin>>n;
    vec<ll> a(n);
    rAuto(a);
    sort(ALL(a));
    ll tot = accumulate(ALL(a), 0LL);
    int minus = 0;
    while (tot<pAcc[n-1] && n>1) { 
        n--;
        tot-=a[minus];
        minus++;
    }
    cout<<minus<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    fillSieve();

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


