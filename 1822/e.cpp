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

bool notPalin(string s, int n)
{
    for (int i = 0; i < n / 2; ++i)
    {
        if (s[i] == s[n - i - 1])
            return false;
    }
    return true;
}

void solve()
{
    int n, ans = 0;
    cin >> n;
    string s;
    cin >> s;
    char before;
    if (n % 2)
    {
        cout << -1 << '\n';
        return;
    }
    set<char> letters;
    for (int i = 0; i < (n / 2); ++i)
    {
        if (s[i] == s[n - i - 1])
        {
            if (!i)
            {
                bool pos = false;
                for (int j = 0; j < (n / 2) && !pos; ++j)
                {
                    if (s[i] != s[j])
                    {
                        before = s[i];
                        s[i] = s[j];
                        s[j] = before;
                        ans++;
                        pos = true;
                    }
                }
                if (!pos)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
            else
            {
                bool pos = false;
                for (int j = 0; j < (n / 2) && !pos; ++j)
                {
                    if (s[i] != s[j])
                    {
                        before = s[i];
                        s[i] = s[j];
                        s[j] = before;
                        pos = true;
                        ans++;
                    }
                }
                if (!pos)
                {
                    for (int j = i; j >= 0 &&!pos; --j)
                    {
                        if (s[j] != s[i])
                        {
                            before = s[i];
                            s[i] = s[j];
                            s[j] = before;
                            pos= true;
                            ans++;
                        }
                    }
                }
                if (!pos)
                {
                    cout << -1 << '\n';
                    return;
                }
            }
        }
    }
    DEBUG(ans);
    DEBUG(s);
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
