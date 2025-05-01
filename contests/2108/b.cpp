#include <bits/stdc++.h>
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
#define snd second
#define fst first
#define ll long long
const int MAX = 2e5+20, MOD = 1e9+7;
int t=1;
  
void solve(){
    ll n, x;cin>>n>>x;
    if(n==1 && x==0){
        cout<<-1<<endl;
        return;
    }
    ll msbit = -1;
    ll countbits = 0;
    for(ll i = 0; i<30; ++i){
        if(!TEST(x, i)){
            msbit = i;
            break;
        }
    }
    for(ll i = 0; i<30; ++i){
        if(TEST(x, i)){
            countbits++;
        }
    }
    if(n<=countbits){
        cout<<x<<endl;
        return;
    }

    ll sum = 0;

    if(!countbits){
        if(n%2)sum+=3+2+(n-2);
        else {
            sum+=n;
        }
    }

    else{
        for(ll i = 30; i>=0; --i){
            if(TEST(x,i)){
                if(countbits==1 && (n==2)){
                    sum+=((1LL<<i)| (1LL<<msbit))+(1LL<<msbit);
                    DEBUG("1");
                    // DEBUG(sum);
                    break;
                }
                else if(countbits==1 && (n%2)){
                    sum+=(1LL<<i)+(n-1);
                    // DEBUG("2");
                    // DEBUG(sum);
                    break;
                }
                else if(countbits==1 && (!(n%2))){
                    sum+=(1LL<<i)+(0+2)+(n-2);
                    // DEBUG("3");
                    // DEBUG(n);
                    break;
                }
                else if(countbits>1){
                    sum+=(1LL << i);
                    n--;
                }
                else {
                    // DEBUG(n);
                }

                countbits--;
            }         
        }

    }
    cout<<sum<<endl;

}
  
int main(){
   ios::sync_with_stdio(0);
   cin.tie(0); cout.tie(0);
   cin>>t;
   while(t--){
      solve();
   }return 0;
}
  