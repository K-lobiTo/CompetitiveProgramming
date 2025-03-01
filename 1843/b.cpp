#include <bits/stdc++.h>
using namespace std;
  
#define SET(m, i) ((m) | (1ULL << (i)))
#define TEST(m, i) ((m) & (1ULL << (i)))
#define CLEAR(m, i) ((m) &~ (1ULL << (i)))
#define DEBUG(n) cout<<#n<<" = "<<n<< endl
#define MSET(arr, x, n) (memset(arr, x, (n)*sizeof(arr[0])))
#define ALL(v) (v).begin(), (v).end()
#define vec vector
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    int n;cin>>n;
    vec<int>nums(n);
    ll ans[2];ans[0]=0;ans[1]=0;
    for(auto&e:nums)cin>>e;
    bool changing = false;
    for(int i = 0; i<n ; ++i){
        ans[0]+=abs(nums[i]);
        if(!changing){
            if(nums[i]<0){
                changing=true;
                ans[1]++;
            }
        }
        else if(nums[i]>0){
            changing = false;
        } 
    }
    cout<<ans[0]<<' '<<ans[1]<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while(t--){
solve();
}return 0;
}
  