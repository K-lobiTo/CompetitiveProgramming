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


ll getNum(int x, int y, int n){
    ll ans = 0;
    while (n) {
        if(x> 1LL<<(n-1) && y>1LL<<(n-1)){
            ans+= 1LL<<(2*n-2);
            // DEBUG("a");
            x-=1LL<<(n-1);
            y-=1LL<<(n-1);
        }
        else if(x<= 1LL<<(n-1) && y<= 1LL<<(n-1)){
            // DEBUG("b");
        }
        else if(y> 1LL<<(n-1) && x <= 1LL<<(n-1)){
            ans+=3 * 1LL<<(2*n-2);
            // DEBUG("c");
            y-=1<<(n-1);
        }
        else if(x>1LL<<(n-1) && y<=1LL<<(n-1)){
            ans+=1LL<<(2*n-1);
            // DEBUG("d");
            x-=1LL<<(n-1);
        }
        // else { DEBUG("what?");
        //     DEBUG(x);
        //     DEBUG(y);
        //     DEBUG(n);
        // }
        n--;
    }
    return ans;
}

pair<int, int> getCords(ll d, int n){
    int x = 0, y = 0;
    while(n){
        //x,y >
        if(d> 1LL<<(2*n-2) && d<= 1LL<<(2*n-1)){
            d-=1LL<<(2*n-2);
            x+=1LL<<(n-1);
            y+=1LL<<(n-1);
        }// y<= x>
        else if(d> 1LL<<(2*n-1) && d<= 3LL<<(2*n-2)){
            d-=1LL<<(2*n-1);
            x+=1LL<<(n-1);
        } // x <= y>
        else if(d>3<<(2*n-2) && d<= 1LL<<(2*n)){
            d-=3LL<<(2*n-2);
            y+=1LL<<(n-1);
        } //x, y <=
        else if(d<=1LL<<(2*n-2)){
        }
        n--;
        
    }
    return {x, y};
}
  
void solve(){
    int n, q; cin>>n>>q;
    string s;
    for (int i = 0; i < q; i++) {
        cin>>s;
        if (s[0]=='-') {
            int x, y;
            cin>>x>>y;
            cout<<getNum(x, y, n)+1<<endl;
        }
        else {
            ll d; cin>>d;
            pair<int, int> cords = getCords(d, n);
            cout<<cords.first+1<<' '<<cords.second+1<<endl;
        }
    }
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


