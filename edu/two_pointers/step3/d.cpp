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
vec<vec<int>> clothes(4);

int diff(int i1, int i2, int i3, int i4){
    if(i1 >= clothes[0].size() || i2 >= clothes[1].size() ||i3 >= clothes[2].size() ||i4 >= clothes[3].size())return 1e9;
    return max({clothes[0][i1], clothes[1][i2], clothes[2][i3], clothes[3][i4]})
        - min({clothes[0][i1], clothes[1][i2], clothes[2][i3], clothes[3][i4]});
}

int minidx(int i1, int i2, int i3, int i4){
    int a = clothes[0][i1];
    int b = clothes[1][i2];
    int c = clothes[2][i3];
    int d = clothes[3][i4];
    int m = (min({a, b, c, d}));
    if(m == a) return 0;
    if(m == b) return 1;
    if(m == c) return 2;
    if(m == d) return 3;
    return 1e9;
}
  
void solve(){
    int inp, inp2;
    for (int i = 0; i < 4; i++) {
        cin>>inp;
        for (int j = 0; j < inp; j++) {
            cin>>inp2;
            clothes[i].push_back(inp2);
        }
        sort(ALL(clothes[i]));
    }
    vec<int> it(4);

    int prevdiff = 1e9;
    int ans = 1e9+1;
    vec<int> ansoutput = {1, 1, 1, 1};
    while(1){
        int curdiff = diff(it[0], it[1], it[2], it[3]);
        while(diff(it[0]+1, it[1], it[2], it[3]) < curdiff){
            it[0]++;
            curdiff = diff(it[0], it[1], it[2], it[3]);
        }
        while(diff(it[0], it[1]+1, it[2], it[3]) < curdiff){
            it[1]++;
            curdiff = diff(it[0], it[1], it[2], it[3]);
        }
        while(diff(it[0], it[1], it[2]+1, it[3]) < curdiff){
            it[2]++;
            curdiff = diff(it[0], it[1], it[2], it[3]);
        }
        while(diff(it[0], it[1], it[2], it[3]+1) < curdiff){
            it[3]++;
            curdiff = diff(it[0], it[1], it[2], it[3]);
        }
        if(curdiff < ans){
            ans =curdiff;
            ansoutput.clear();
            for (int i = 0; i < 4; i++) {
                ansoutput.push_back(clothes[i][it[i]]);
            }
        }
        if(curdiff == prevdiff){
            it[minidx(it[0], it[1], it[2], it[3])]++;
            curdiff = diff(it[0], it[1], it[2], it[3]);
        }
        if(curdiff == 1e9)break;
        prevdiff = curdiff;
    }
    for(auto &e:ansoutput)cout<<e<<' ';
    cout<<endl;


}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    while(t--){
        solve();
    }
    return 0;
}


