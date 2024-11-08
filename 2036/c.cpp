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
int t = 1;

void solve()
{
    int q, p, len;
    char v;
    string bin;
    cin >> bin >> q;
    len = bin.size();
    // DEBUG(bin);
    // DEBUG(len);
    cin >> p >> v; // p-1
    bin[p - 1] = v;
    cout << (bin.find("1100") != string::npos ? "YES" : "NO") << '\n';
    for (int i = 1; i < q; i++)
    {
        cin >> p >> v; // p-1
        bin[p - 1] = v;
        DEBUG(bin); // I should verify that there's not a previous one present
        cout << (bin.substr(max(0,p-4), min(8, 8-(len-p))).find("1100") != string::npos ? "YES" : "NO") << '\n';
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
