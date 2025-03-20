
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
    int n, k, b, c, ans = 0;
    cin >> n >> k;
    vec<int> brands(k, 0);
    // DEBUG('yes');
    for (int i = 0; i < k; i++)
    {
        cin >> b >> c;
        brands[b - 1] += c;
    }
    sort(ALL(brands));
    for (int i = 0; i < n && i < k; i++)
    {
        ans += brands[k - 1 - i];
    }
    cout << ans << '\n';
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
