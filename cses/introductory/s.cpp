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
pair<vec<int>, multiset<int>> G[MAX];

string s;

void priMat(vec<int> mat ){
    for(int i = 0; i<7; ++i){
        for(int j = 0; j<7; ++j){
            cout<<(TEST(mat[i], j)? "0":"#");
        }
        cout<<'\n';
    }
    cout<<"\n\n";
}
bool test(int i, int j, vec<int> mat){
    if(i<0 || i>6 || j<0 || j>6)return false; 
    if(TEST(mat[i], j))return false;
    return true;
}

void backtrack(ll &r, vec<int> &mat, int idx, int i, int j){
    // DEBUG("Backtrack");
    if(i == 6 && j == 0){r++; return; DEBUG("END");}
    // priMat(mat);
    if(idx==48) return;
    if(s[idx]=='R'){
        if(test(i, j+1, mat)){
            mat[i]=SET(mat[i], j+1);
            backtrack(r, mat, idx+1, i, j+1);
            mat[i]=CLEAR(mat[i], j+1);
        }
    }
    else if(s[idx]=='L'){
        if(test(i, j-1, mat)){
            mat[i]=SET(mat[i], j-1);
            backtrack(r, mat, idx+1, i, j-1);
            mat[i]=CLEAR(mat[i], j-1);
        }
        
    }
    else if(s[idx]=='U'){
        if(test(i-1, j, mat)){
            mat[i-1]=SET(mat[i-1], j);
            backtrack(r, mat, idx+1, i-1, j);
            mat[i-1]=CLEAR(mat[i-1], j);
        }
        
    }
    else if(s[idx]=='D'){
        if(test(i+1, j, mat)){
            mat[i+1]=SET(mat[i+1], j);
            backtrack(r, mat, idx+1, i+1, j);
            mat[i+1]=CLEAR(mat[i+1], j);
        }
    }
    else{
        if(test(i, j+1, mat)){
            mat[i]=SET(mat[i], j+1);
            backtrack(r, mat, idx+1, i, j+1);
            mat[i]=CLEAR(mat[i], j+1);
        }
        if(test(i, j-1, mat)){
            mat[i]=SET(mat[i], j-1);
            backtrack(r, mat, idx+1, i, j-1);
            mat[i]=CLEAR(mat[i], j-1);
        }
        if(test(i-1, j, mat)){
            mat[i-1]=SET(mat[i-1], j);
            backtrack(r, mat, idx+1, i-1, j);
            mat[i-1]=CLEAR(mat[i-1], j);
        }
        if(test(i+1, j, mat)){
            mat[i+1]=SET(mat[i+1], j);
            backtrack(r, mat, idx+1, i+1, j);
            mat[i+1]=CLEAR(mat[i+1], j);
        }
    }
    
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t=1;
    //cin>>t;
    int idx = 0;
    while(t--){
        ll resp = 0;
        cin>>s;
        vec<int> mat(7, 0);
        mat[0] = SET(mat[0], 0);
        // priMat(mat);
        backtrack(resp, mat, 0, 0, 0);
        cout<<resp<<'\n';
    }
    
    return 0;
}