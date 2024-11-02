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

bool divide(int n, int m)
{
    if (n == m)
        return true;
    if (n % 3)
        return false;
    int small = n / 3;
    if (small == m || 2 * small == m)
        return true;
    return (divide(small, m) || divide(2 * small, m));
}

void solve()
{
    int n, m;
    cin >> n >> m;
    cout << (divide(n, m) ? "YES" : "NO") << '\n';
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
