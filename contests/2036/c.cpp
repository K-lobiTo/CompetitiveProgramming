#include <bits/stdc++.h>
using namespace std;

#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) & ~(1ULL << (i)))
#define DEBUG(n) cout << #n << " = " << n << endl
#define MSET(arr, x, n) (memset(arr, x, (n) * sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5 + 20, MOD = 1e9 + 7;
int t = 1, len;
string bin;


bool there_is(int e){
    if(e<0 || e>=len-3)return false;
    string ans = "";ans+=bin[e];ans+=bin[e+1];ans+=bin[e+2];ans+=bin[e+3];
    if(ans == "1100")return true;
    return false;
}

void solve()
{
    int q, p, thereis=0;
    bool prev, post;
    char v;
    cin >> bin >> q;
    len = bin.size();
    for(int i=0;i<len;++i)if(there_is(i))thereis++;
    for (int _ = 0; _ < q; ++_)
    {
        cin >> p >> v; // p-1
        if(bin[p-1]!=v){
            prev = there_is(p-1) || there_is(p-2)|| there_is(p-3)|| there_is(p-4);
            bin[p - 1] = v;
            post = there_is(p-1) || there_is(p-2)|| there_is(p-3)|| there_is(p-4);
            thereis += post-prev;
        }
        
        cout << (thereis ? "YES" : "NO") << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
