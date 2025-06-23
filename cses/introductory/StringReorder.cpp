#include <bits/stdc++.h>
#include <cstddef>
#include <iterator>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    string s; cin>>s;
    int n = s.size();
    map<int, int> repetitions;
    for(auto &e:s){
        repetitions[e]++;
    }
    vec<pair<int, int>> chs;
    for(auto &e:repetitions){
        chs.push_back(e);
    }
    string ans = "";
    while(!chs.empty()){
        if(chs.size() == 1 && ((int)ans.back() == chs[0].first)){
            cout<<-1<<endl;
            return;
        }
        bool flag = false;
        for (int i = 0; i < (int)chs.size(); i++) {
            if(ans.back()!= chs[i].first && chs[i].second > n/2){
                chs[i].second--;
                ans+=chs[i].first;
                if(!chs[i].second)chs.erase(chs.begin()+i);
                flag = true;
                break;
            }
        }
        n--;
        if(flag) continue;
        if((char)chs[0].first == (int)ans.back()){
            ans+=((char)chs[1].first);
            chs[1].second--;
            if(!chs[1].second){
                chs.erase(chs.begin()+1);
            }
        }
        else {
            ans+=((char)chs[0].first);
            chs[0].second--;
            if(!chs[0].second){
                chs.erase(chs.begin());
            }
        }
    }
    cout<<ans<<endl;
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


