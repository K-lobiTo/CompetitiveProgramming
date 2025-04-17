
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
    int n, a, b;
    cin>>n;
    vec<pair<int, int>> w;
    vec<int> fixed1(2*n +1);
    vec<bool> fixed2(2*n +1);

    for(int i = 0; i<n; ++i){
        cin>>a>>b;
        w.push_back({a,b});
        if(a==b){
            if(fixed1[a]){
                fixed2[a] = 1;
            }
            else fixed1[a] = 1;
        }
    }
    fixed1.insert(fixed1.begin(), 0);

    partial_sum(ALL(fixed1), fixed1.begin());

    for(auto& [w1, w2] : w){
        if(w1!=w2){
            cout<<((fixed1[w2+1]-fixed1[w1])<(w2-w1+1));
        }
        else {
            cout<<(!fixed2[w1]);
        }
    }
    cout<<endl;
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  