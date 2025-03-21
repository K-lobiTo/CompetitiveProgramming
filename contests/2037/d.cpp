
#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){

    int n, m; 
    ll L, l, r;
    cin>>n>>m>>L; 
    vec<pair<pair<ll, ll>, bool>> elements;
    for(int i = 0; i<n; ++i){
        cin>>l>>r;
        elements.push_back({{l, r}, false});
    }
    for(int i = 0; i<m; ++i){
        cin>>l>>r;
        elements.push_back({{l, r}, true});
    }
    sort(ALL(elements));
    vec<pair<ll, bool>> path;
    for(auto&[par, powerUp]:elements){
        if(powerUp){
            path.push_back({par.second, true});
        }
        else{
            path.push_back({2+(par.second - par.first), false});
        }
    }

    priority_queue<ll> powers;
    ll ans = 0;
    ll power = 1;
    for(auto&[value, powerUp]:path){
        if(powerUp)powers.push(value);
        else{
            while (power< value){
                if(powers.empty()){cout<<-1<<endl; return;}
                ans++;
                power+=powers.top(); powers.pop();
            }
        }
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
  