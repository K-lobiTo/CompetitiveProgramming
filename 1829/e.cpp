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

int memo[1001][1001];
int vis[1001][1001];
int n, m, maxvol = 0;

int vol(int i, int j)
{
    if (i < 0 || j < 0)
        return 0;
    if (!memo[i][j] || vis[i][j])
        return 0;
    vis[i][j] = 1;
    return memo[i][j] + vol(i + 1, j) + vol(i, j + 1) + vol(i - 1, j) + vol(i, j - 1);
}

void solve()
{

    maxvol = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        MSET(vis[i], 0, 1001);
        for (int j = 0; j < m; j++)
        {
            cin >> memo[i][j];
            memo[i + 1][j + 1] = memo[i][j + 1] = memo[i + 1][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j])
                maxvol = max(maxvol, vol(i, j));
        }
    }
    cout << maxvol << '\n';
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
