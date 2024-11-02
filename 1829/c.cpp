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
    int c, minut, mina, minb, minabs;
    string bin;
    mina = minb = minabs = MOD;
    cin >> c;
    while (c--)
    {
        cin >> minut;
        cin >> bin;
        if (bin[0] == '1' && bin[1] == '1' && minut < minabs)
            minabs = minut;
        else if (bin[0] == '1' && mina > minut)
            mina = minut;
        else if (bin[1] == '1' && minb > minut)
            minb = minut;
    }
    minabs = min(minabs, mina + minb);
    if (minabs < MOD)
    {
        cout << minabs << '\n';
        return;
    }
    cout << -1 << '\n';
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
