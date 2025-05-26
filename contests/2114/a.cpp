#include <bits/stdc++.h>
#include <string>
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
    string s;
    char c;
    for (size_t i = 0; i < 4; i++) {
        cin>>c; s.push_back(c);
    }
    int year = stoi(s);
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if(((i+j)*(i+j)) == year){
                cout<<i<<' '<<j<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
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


