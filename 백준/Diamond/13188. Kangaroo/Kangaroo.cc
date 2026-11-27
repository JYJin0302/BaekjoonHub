#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll dp[2020];
ll ndp[2020];
void solve(){

    int n, s, f;
    cin >> n >> s>> f;

    if (s > f) swap(s, f);

    dp[1] = 1;
    for(int i = 2; i <= n; i++){
        memset(ndp, 0, sizeof ndp);
        if (i < s){
            for(int j = 1; j <= i; j++){
                ndp[j] = (dp[j-1] + dp[j+1]) % mod * j % mod;
            }
        }
        else if (i == s){
            for(int j = 1; j <= i; j++){
                ndp[j] = (dp[j-1] + dp[j]) % mod;
            }
        }
        else if (i < f){
            for(int j = 1; j <= i; j++){
                ndp[j] = dp[j-1] * (j - 1) % mod + dp[j+1] * j % mod;
                ndp[j] %= mod;
            }
        }
        else if (i == f){
            for(int j = 1; j <= i; j++){
                ndp[j] = (dp[j-1] + dp[j]) % mod;
            }
        }
        else{
            for(int j = 1; j <= i; j++){
                if (j >= 2) ndp[j] += dp[j-1] * (j - 2) % mod;
                ndp[j] += dp[j+1] * j % mod;
                ndp[j] %= mod;
            }
        }
        swap(dp, ndp);
    }

    cout << dp[1] << '\n';
    
}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
