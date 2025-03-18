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
vec<int> iniMat(8, 0);

bool test(vec<int> &mat, int i, int j){
    if(i>7 || j>7)return false;
    if(TEST(iniMat[i], j))return false;
    if (mat[i])return false;
    for(int it = 0; it<8; ++it)if(TEST(mat[it], j))return false;
    while(i!=0 && j!=0){
        i--;j--;
    }
    for(;i<8 && j<8; ++i, ++j)if(TEST(mat[i], j) || TEST(mat[j], i))return false;
    return true;
}

void solve(){
    char ch; 
    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8; ++j){
            cin>>ch;
            if(ch=='*'){
                iniMat[i] = SET(iniMat[i], j);
            }
        }
    }
    stack<pair<int, vec<int>>> s; 
    for(int i = 0; i<8; ++i){
        vec<int> subM(8);
        pair<int, vec<int>> e={0, subM};
        s.push(e);
    }
    ll ans = 0;
    while (!s.empty()){
        auto &[idx, subMat] = s.top();
        s.pop();
        if(idx == 8)ans++;
        else{
            for(int i = 0; i<8; ++i){
                if(test(subMat, idx, i)){
                    vec<int> nSubMat = subMat;
                    nSubMat[idx] = SET(nSubMat[idx], i);
                    s.push({idx+1, nSubMat});
                }
            }
        }
    }
    cout<<ans<<'\n';
    

}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
while(t--){
solve();
}return 0;
}
  