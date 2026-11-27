#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;
ll dp[1010][1010][2];

void solve(){
    
    dp[1][0][0] = 1;
    for(int i = 1; i < 1000; i++){
        for(int j = 0; j < i; j++){
            // dp[i][j][0] -> dp[i+1][?][?]
            if(j) (dp[i+1][j-1][0] += dp[i][j][0] * j % mod) %= mod;
            (dp[i+1][j+1][1] += dp[i][j][0] * 2 % mod) %= mod;
            (dp[i+1][j][0] += dp[i][j][0] * (i + 1 - j - 2) % mod) %= mod;

            // dp[i][j][1] -> dp[i+1][?][?]
            if (j) (dp[i+1][j-1][0] += dp[i][j][1] * (j - 1) % mod) %= mod;
            (dp[i+1][j][1] += dp[i][j][1] % mod) %= mod;
            (dp[i+1][j][0] += dp[i][j][1] * (i - j) % mod) %= mod;
            (dp[i+1][j+1][1] += dp[i][j][1] % mod) %= mod;
        }
    }


    // for(int i = 1; i <= 10; i++){
    //     for(int j =0; j < i; j++){
    //         cout << "(" << dp[i][j][0] << ' ' << dp[i][j][1] << ") ";
    //     }
    //     cout << '\n';
    // }


    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        ll ans = dp[n][k][0] + dp[n][k][1];
        cout << ans % mod << '\n';
    }

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
