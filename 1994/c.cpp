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

// 1 2 3 4

void solve()
{
    int n;
    ll x, ans = 0;
    cin >> n >> x;
    vec<ll> a(n);
    for (auto &e : a)
        cin >> e;
    partial_sum(ALL(a), a.begin());
    // a.insert(a.begin(), 0);
    // for (auto &e : a){
    //     DEBUG(e);
    // }
    vec<int> dp(n+2);
    for (int i = (n-1); i >=0; --i)
    {
        ll sr = x; if(i)sr+=a[i-1];
        int r = upper_bound(ALL(a), sr) - a.begin();
        // DEBUG(sr);
        // DEBUG(i);
        // DEBUG(r);
        dp[i]=dp[r+1]+r-i;

        // DEBUG(dp[i]);
        ans+=dp[i];
    }
    // for(auto &dpi:dp)DEBUG(dpi);

    cout << ans << '\n';
    // cout << accumulate(ALL(dp), 0) << '\n';
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
