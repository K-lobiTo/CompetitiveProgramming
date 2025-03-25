#include <bits/stdc++.h>
using namespace std;
 
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<<endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 5e5+20, MOD = 1e9+7;
int t=1, n, arr[MAX], u, v;
 
string s;
ll ans = 0;
int mat[9];
 
bool test(const int &i, const int &j){
    // if(i<1 || i>7 || j<1 || j>7)return false; 
    if(TEST(mat[i], j))return false;

    if((TEST(mat[i-1], j) && TEST(mat[i+1], j) && !(TEST(mat[i], j-1) || TEST(mat[i], j+1))))return false;
    if((TEST(mat[i], j-1) && TEST(mat[i], j+1)) && !(TEST(mat[i-1], j) || TEST(mat[i+1], j)))return false;
    return true;
}
 
void backtrack(int idx, int i, int j){
    if(i == 7 && j == 1){
        if(idx == 48){
            ans++;
        }
        return;
    }
    // if(idx==48) return; // this is impossible without getting through (0,6) [the previous if]

    mat[i] = SET(mat[i], j);
    if(s[idx]=='?' || s[idx]=='R'){
        if(test(i, j+1)){
            backtrack( idx+1, i, j+1);
        }
    }
    if(s[idx]=='?' || s[idx]=='L'){
        if(test(i, j-1)){
            backtrack(idx+1, i, j-1);
        }
        
    }
    if(s[idx]=='?' || s[idx]=='U'){
        if(test(i-1, j)){
            backtrack( idx+1, i-1, j);
        }
        
    }
    if(s[idx]=='?' || s[idx]=='D'){
        if(test(i+1, j)){
            backtrack( idx+1, i+1, j);
        }
    }
    mat[i] = CLEAR(mat[i], j);
    return;
}
 
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    cin>>s;
    for(int i = 0; i<9; ++i){
        mat[0] = SET(mat[0], i);
        mat[8] = SET(mat[0], i);
        mat[i] = SET(mat[i], 8);
        mat[i] = SET(mat[i], 0);
    }
    
    // vec<int> mat(7, 0);
    backtrack( 0, 1, 1);
    cout<<ans<<'\n';
    
    return 0;
}