
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
  
bool solve(){
    string p,s;cin>>p>>s;
    ll psize = p.size();
    ll ssize = s.size();
    vec<ll> sumsP;
    vec<ll> sumsS;
    if(ssize < psize)return false;
    if(s[0]!=p[0])return false; 
    sumsP.push_back(1);
    sumsS.push_back(1);
    for(int i = 1; i<psize; ++i){
        if(p[i]!=p[i-1])sumsP.push_back(1);
        else sumsP.back()++;
    }
    for(int i = 1; i<ssize; ++i){
        if(s[i]!=s[i-1])sumsS.push_back(1);
        else sumsS.back()++;
    }

    ll pSums = sumsP.size();
    ll sSums = sumsS.size();

    if(pSums != sSums)return false;

    for(int i = 0; i<pSums; ++i){
        if(((2*sumsP[i])<sumsS[i]) || (sumsS[i]<sumsP[i]))return false;
    }


    return true;


    // for(int i = 1; i< (p.size()-1); ++i){
    //     if((p[i] != p[i-1]) && ( p[i]!=p[i+1])){
    //         p.insert(p.begin()+i, p[i]);
    //     }
    // }
    // ll psize = p.size();
    // if(p[psize-1]!=p[psize-1])p.push_back(p[psize-1]);

    // for(int i = 1; i< (s.size()-1); ++i){
    //     if((s[i] != s[i-1]) && ( s[i]!=s[i+1])){
    //         s.insert(s.begin()+i, s[i]);
    //     }
    // }

    // ll ssize = s.size();
    // if(s[ssize-1]!=s[ssize-1])s.push_back(s[ssize-1]);
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
cout<<(solve() ? "YES\n" : "NO\n");
}return 0;
}
  