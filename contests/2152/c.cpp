#include <bits/stdc++.h>
#include <numeric>
using namespace std;
  
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define rAuto(arr) for(auto &e:arr)cin>>e
#define ALL(v) (v).begin(), (v).end()
#define rALL(v) (v).rbegin(), (v).rend()
#define vec vector
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;

struct co{
    int size;
    vec<int> ceros;
    vec<int> ones;
    vec<int> neutral;

    co(vec<int> input){
        size = input.size();
        ceros.assign(size+1, 0);
        ones.assign(size+1, 0);
        neutral.assign(size+1, 0);
        int prev = input[0];
        for (int i = 0; i < size; i++) {
            if(input[i])ones[i+1] = 1;
            else ceros[i+1] = 1;

            if(i && input[i] == prev)neutral[i+1] = 1;
            prev = input[i];
        }
        // cout<<endl;
        partial_sum(ALL(ceros), ceros.begin());
        partial_sum(ALL(ones), ones.begin());
        partial_sum(ALL(neutral), neutral.begin());
        // for(auto &e:ceros)cout<<e<<" ";
        // cout<<endl;
        // for(auto &e:ones)cout<<e<<" ";
        // cout<<endl;
        // for(auto &e:neutral)cout<<e<<" ";
        // cout<<endl;
    }

    bool valid(int l, int r){
        l--;
        int cerosAmount = ceros[r] - ceros[l];
        int onesAmount = ones[r] - ones[l];
        return !(cerosAmount%3) && !(onesAmount%3);
    }

    int steps(int l, int r){
        bool extra = !(neutral[r] - neutral[l]);
        l--;
        int cerosAmount = ceros[r] - ceros[l];
        int onesAmount = ones[r] - ones[l];
        return cerosAmount/3 + onesAmount/3 + extra;
    }

};
  
void solve(){
    int n, q; cin>>n>>q;
    vec<int> a(n); rAuto(a);
    co subans(a);
    int l, r;
    while(q--){
        cin>>l>>r;
        if(!subans.valid(l, r))cout<<-1<<endl;
        else{
            cout<<subans.steps(l, r)<<endl;
        }
    }
}
  
int32_t main(){
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}


