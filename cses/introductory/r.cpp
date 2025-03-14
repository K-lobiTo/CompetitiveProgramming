
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
unsigned ll precal = 1;
ll nums = 1;
string precalc = "0";
  
ll intervalSum(int nDigit){
    return nDigit*pow(10, nDigit-1)*9;
}

// k - 10^(log10(k)-1) * log10(k); 
int nDigits(int k){
    return floor(log10(k))+1;
}

int mostSignDig(int k){
    return k/pow(10, nDigits(k)-1);
}

void solve(){
    ll k;
    cin>>k;
    // cout<<precalc<<'\n';
    if(k<189){cout<<precalc[k]<<'\n'; return;}
    // if(k)
    int i = 17;
    // DEBUG(mostSignDig(582));
    while ((intervalSum(i)>=180) && (k>189))
    {
        DEBUG(i);
        DEBUG(intervalSum(i));
        while ((k>intervalSum(i)) && (k>189))
        {
            // DEBUG(k);
            k-=intervalSum(i);
            DEBUG(k);
        }
        
        // if((mostSignDig(k) * intervalSum(i))<k){
        //     k-=(mostSignDig(k) * intervalSum(i));
        //     DEBUG(k);
        // }
        --i;
    }
    k-=9;
    cout<<precalc[189-k]<<'\n';
    

    // cout<<precalc<<'\n';
//     cout<<precal<<'\n';
    cout<<precalc.size()<<'\n';
}
  
int main(){
ios::sync_with_stdio(0);
cin.tie(0); cout.tie(0);
cin>>t;
while (nums<100){
    precalc = precalc + to_string(nums);
    precal+=nDigits(nums);
    nums++;
}
while(t--){
    solve();
}return 0;
}
  