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
    string s; cin>>s;
    int l = 0, r = n-1;
    int l2 = 0, r2 = n-1;
    vec<char> ans(n, '+');
    int cant2 = 0;
    for(auto e:s){
        if(e=='2')cant2++;
        l2 = max(l2, l);
        r2 = min(r2, r);
        if(e=='2'){
            ans[l2] = '?';
            ans[r2] = '?';
            if(r == l)ans[r] = '-';
            l2++; r2--;
        }
        else if(e=='0'){
            if(ans[l]=='?'){
                ans[l2] = '?';
                l2++;
            }
            ans[l] = '-';
            l++;
        }
        else {
            if(ans[r]=='?'){
                ans[r2] = '?';
                r2--;
            }
            ans[r] = '-';
            r--;
        }
    }
    if(//cant2==n 
       k==n
            //|| (k==n && cant2==()
                )for(auto &e:ans)e='-';
    for(auto &e:ans)cout<<e;
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


