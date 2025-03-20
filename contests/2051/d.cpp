
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

void solve(){
    int n;
    ll x, y, tot = 0, ans = 0;
    cin >> n >> x >> y;
    vec<int> a(n);
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        tot += a[i];
    }
    sort(ALL(a));
    if(tot<=x || a[0]>y){
        cout<<"0\n";
        return;
    }
    auto it=a.begin();
    for(int i = 0; n-i-1; ++i){
        ++it;
        auto ltx=upper_bound(it, a.end(), tot - x - a[i]);
        auto lty=lower_bound(it, a.end(), tot - y - a[i]);
        ans+=ltx-lty; // (a.end()-lty)-(a.end()-ltx) is ltx - lty
    }
    cout<<ans<<'\n';
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
