
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
    int n, m, prev;
    cin >> n >> m;
    vec<vec<int>> mat;
    mat.assign(n, vec<int>(m, 0));
    for (auto &r : mat)
        for (auto &c : r)
            cin >> c;

    for (auto &r : mat)
    {
        for (int i = 0; i < m; ++i)
        {
            if (!i)
                prev = r[i];
            r[i] = r[(i + 1) % m];
            if (i == (m - 1))
                r[i] = prev;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (!i)
            prev = mat[i][0];
        mat[i][0] = mat[(i + 1) % n][0];
        if (i == (n - 1))
            mat[i][0] = prev;
    }
    if (n == (m == 1))
    {
        cout << -1 << '\n';
        return;
    }
    for (auto &r : mat)
    {
        for (auto &c : r)
            cout << c << ' ';
        cout << '\n';
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
