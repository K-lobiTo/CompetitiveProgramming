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
    int n, k;
    cin >> n >> k;
    if (n == 1 || ((n + 1) / 2 == k))
    {
        cout << 1 << '\n'
             << 1 << '\n';
        return;
    }
    if (!(n - k) || k == 1)
    {
        cout << -1 << '\n';
        return;
    }
    if (!(k % 2))
    {
        cout << 3 << '\n'
             << 1 << ' ' << k << ' ' << k + 1 << '\n';
        return;
    }
    if ((n - (k + 1)) > 0 && (n - (k + 1)) % 2)
        cout << 3 << '\n'
             << 1 << ' ' << k - 1 << ' ' << k + 2 << '\n';
    else
    {
        cout << -1 << '\n';
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
