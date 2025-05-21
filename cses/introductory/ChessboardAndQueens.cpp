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

void priMat(vec<int> mat ){
    for(int i = 0; i<8; ++i){
        for(int j = 0; j<8; ++j){
            if(TEST(iniMat[i], j))cout<<"*";
            else{
                cout<<(TEST(mat[i], j)? "Q":"#");
            }
        }
        cout<<'\n';
    }
    cout<<"\n\n";
}

bool test(vec<int> &mat, int i, int j){
    // for(auto &e:mat)cout<<e<<endl;
    // DEBUG(i);
    // DEBUG(j);
    if(TEST(iniMat[i], j))return false;
    if (mat[i])return false;
    for(int it = 0; it<8; ++it)if(TEST(mat[it], j))return false;
    int i2 = i, j2 = j;
    for(;i>=0 && j>=0; --i, --j)if(TEST(mat[i], j))return false;
    for(;i2>=0 && j2<8; --i2, ++j2)if(TEST(mat[i2], j2))return false;
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
    vec<int> subM(8, 0);
    s.push({0, subM});

    ll ans = 0;
    while (!s.empty()){
        pair<int, vec<int>> act = s.top();
        s.pop();
        int idx = act.first;
        vec<int> subMat = act.second;
        // DEBUG(idx);
        if(idx == 8){
            ans++;
            // priMat(subMat);
        }
        else{
            for(int i = 0; i<8; ++i){
                if(test(subMat, idx, i)){
                    // for(auto &e:subMat)cout<<e<<endl;
                    vec<int> nSubMat = subMat;
                    nSubMat[idx] = SET(nSubMat[idx], i);
                    // pair<int, vec<int>> e={idx+1, nSubMat};
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
  