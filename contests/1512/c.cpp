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
    int a, b, n; cin>>a>>b;
    n = a+b;
    string s; cin>>s;
    int n0 = a;
    int n1 = b;
    int mid = s.size()/2;
    for (size_t i = 0; i < mid; i++) {
        if(s[i] == '?')s[i] = s[n-i-1];
        if(s[n-i-1] == '?')s[n-i-1] = s[i];
        if(s[i]!=s[n-i-1]){
            cout<<-1<<endl;return;
        }
        if(s[i] == '?' )continue;
        if(s[i] =='0')n0 -=2;
        if(s[i] =='1')n1 -=2;
    }
    for (size_t i = 0; i < mid; i++) {
        if(s[i] == '?' && n0>=2){
            s[i] ='0';
            s[n-i-1] ='0';
            n0-=2;
        }
        else if(s[i] == '?' && n1>=2){
            s[i] ='1';
            s[n-i-1] ='1';
            n1-=2;
        }
    }
    if(n%2){
        if(n0 && (s[mid]=='?' || s[mid] =='0')){
            n0--;
            s[mid]= '0';
        }
        else if(n1 && (s[mid]=='?' || s[mid] =='1')){
            n1--;
            s[mid] = '1';
        }
    }
    if(n0>0 || n1>0 || n1<0 || n0<0){cout<<"-1"<<endl; return;}
    cout<<s<<endl;
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


