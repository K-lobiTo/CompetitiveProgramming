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

string t, p;
int tsize;
int psize;
vec<int> deletions;

bool ok(int d){
    string ev = t;
    for (size_t i = 0; i < d; i++) {
        ev[deletions[i]-1] = '-';
    }

    int idxp = 0;
    for (size_t i = 0; i < tsize; i++) {
        if(idxp ==  psize )break;
        if(p[idxp] == ev[i]){
            idxp++;
        }
    }
    return (idxp == psize);

    // this also works but I prefer the one above:
    //
    // ev.push_back('-');
    // int idxt = 0;
    // for (size_t i = 0; i < psize; i++) {
    //     while (ev[idxt]!=p[i]) {
    //         idxt++;
    //         if(idxt >= tsize)return false;
    //     }
    //     idxt++;
    // }
    // return true;
}

void solve(){
    cin>>t>>p;
    tsize = t.size();
    psize = p.size();
    deletions.resize(tsize);
    rAuto(deletions);
    int l = 0;
    int r = tsize;
    while (l+1<r) {
        int m = (l+r)/2;
        if(ok(m))l = m;
        else r = m;
    }
    cout<<l<<endl;
    
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


