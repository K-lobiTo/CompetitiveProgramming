
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
    int n, k, q, m, r, c, top, bot, mid, itop, ibot;
    char o;
    cin>>n>>k>>q;
    vec<vec<int>> mat(k, vec<int>(n));

    for(int i = 0; i<n; ++i){
        for(int j = 0; j<k; ++j){
            if(i){
                cin>>r;
                mat[j][i]=mat[j][i-1]|r;
            }
            else{
                cin>>mat[j][i];
            }
        }
    }

    for(int i = 0; i<q; ++i){
        ibot = 0;
        itop = n-1;
        cin>>m;
        for(int j = 0; j<m; ++j){
            cin>>r>>o>>c; //row;
            bot = ibot;
            top = itop;
            if(o=='<'){//x<c (searching for the greater top)
                while (bot<top){
                    mid = (bot+top)/2;
                    if(mat[r][mid]<c)bot = mid+1;//mid doesn't work
                    else top = mid;//mid work
                }
                itop = bot;
            }
            else{//x>c (searching for the lower bottom)
                while (bot<top){
                    mid = (bot+top)/2;
                    if(mat[r][mid]>c)top = mid-1; //mid doesn't work
                    else bot = mid+1; //mid work
                }
                ibot = bot;
            }
            DEBUG(itop);
            DEBUG(ibot);
        }
        cout<<(itop>=ibot ? ibot+1 : -1)<<'\n';

    }

  
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
// cin>>t;
while(t--){
solve();
}return 0;
}
  