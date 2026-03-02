#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define vec vector
#define ll long long

const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
int c = 1;
  
void solve(){
    int n; cin>>n;
    vec<int> a(n); for(auto &e:a)cin>>e;
    vec<int> pth1; pth1.push_back(-1);
    vec<int> pth2; pth2.push_back(1);
    int acl1 = 1, acl2 = 0;
    bool b1 = 1, b2 = 1;
    for (int i = 1; i < n; i++) {
        if(abs(a[i]-a[i-1])>1)return void(cout<<0<<endl);
        if(a[i]==a[i-1]){
            if(pth1.back() == -1)pth1.push_back(1);
            else pth1.push_back(-1), acl1++;
            if(pth2.back() == 1)pth2.push_back(-1), acl2++;
            else pth2.push_back(1);
        }
        else if(a[i]<a[i-1]){
            if(pth2.back()== 1)pth2.push_back(1);
            if(pth1.back()== 1)pth1.push_back(1);
            
        }
        else { // a > a_-1
            if(pth1.back() == -1)pth1.push_back(-1),acl1++;
            if(pth2.back() == -1)pth2.push_back(-1),acl2++;
        }
        if(acl1 + ( n-i ) < a[i])b1 = 0;
        if(acl2 + ( n-i ) < a[i])b2 = 0;
    }
    if(a[n-1] != (acl1 + ( pth1.back()==1 )) )b1 = 0;
    if(a[n-1] != ( acl2 + (pth2.back()==1) ))b2 = 0;
    if(pth1.size() < n)b1 = 0;
    if(pth2.size() < n)b2 = 0;
    cout<<b1 + b2<<endl;

}
  
int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0); 

    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


