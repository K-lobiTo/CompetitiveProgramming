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

void solve() {
    int n, ans = 0; cin >> n;
    string s; cin >> s;
    if (n % 2) return void(cout << -1 << endl);
    vec<int> letters(26);
    for (int i = 0; i < n; i++) {
        letters[s[i]-'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if(letters[i] > n/2)return void(cout<< -1<<endl);
    }

    vec<int> coll(26);
    for (int i = 0; i < n/2; i++) {
        if(s[i] == s[n-i-1]){
            coll[s[i]-'a']++;
        }
    }
    set<pair<int, int>> colli;
    for (int i = 0; i < 26; i++) {
        if(coll[i]){
            colli.insert({coll[i], i});
        }
    }
    while(!colli.empty()){
        if(colli.size()==1){
            ans+= (*colli.begin()).first;
            break;
        }

        auto last = prev(colli.end());
        auto llast = prev(last);
        auto &[r1, c1] = *last;
        auto &[r2, c2] = *llast;

        ans++;
        int nr1 = r1 - 1;
        int nr2 = r2 - 1;

        if(nr1)colli.insert({nr1, c1});
        if(nr2)colli.insert({nr2, c2});

        colli.erase(last);
        colli.erase(llast);

    }
    cout<<ans<<endl;
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
