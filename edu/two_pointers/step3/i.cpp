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
    int n, s; cin>>n>>s;
    vec<int> a(n); rAuto(a);
    set<int> cSums;
    set<int> lSums;
    vec<int> cSumsC(s+1);
    int minlen = n+1;
    int l = 0;
    for (int r = 0; r < n; r++) {
        vec<int> cur;
        for(auto &e:cSums){
            if(e + a[r] <= s){
                cur.push_back(e+a[r]);
                cSumsC[e+a[r]]++;
            }
        }
        if(a[r] <= s){
            cur.push_back(a[r]);
            cSumsC[a[r]]++;
        }
        for(auto &e:cur)cSums.insert(e);
        cur.clear();
        while(cSums.find(s)!=cSums.end()){
            // reversion is wrong
            minlen = min(minlen, r-l +1);
            vec<int> toErase;
            for(auto &e:lSums){
                if(e + a[l] <= s){
                    cur.push_back(e+a[l]);
                    --cSumsC[e+a[l]];
                    if(!cSumsC[e+a[l]])toErase.push_back(e+a[l]);
                }
            }
            if(a[l] <= s){
                cur.push_back(a[l]);
                    --cSumsC[a[l]];
                if(!cSumsC[a[l]])toErase.push_back(a[l]);
            }
            for(auto &e:toErase)cSums.erase(e);
            for(auto &e:cur)lSums.insert(e);
            l++;
        }
    }
    cout<<(minlen == n+1 ? -1 : minlen)<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}
