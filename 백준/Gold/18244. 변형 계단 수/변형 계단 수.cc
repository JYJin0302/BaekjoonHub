#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

ll dp[101][10][5];  // 0: 기본, 1: 1상승 2: 2상승 3: 1감소 4 : 2감소

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i <= 9; i++){
        dp[1][i][0] = 1;
    }
    
    for (int i = 2; i <= n; i++){
        
        dp[i][0][3] = (dp[i-1][1][0] + dp[i-1][1][1]) % mod;
        dp[i][0][4] = dp[i-1][1][3];
        dp[i][9][1] = (dp[i-1][8][0] + dp[i-1][8][3]) % mod;
        dp[i][9][2] = dp[i-1][8][1];
        
        for (int j = 1; j <= 8; j++){
            dp[i][j][2] = dp[i-1][j-1][1];
            dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j-1][3] + dp[i-1][j-1][4]) % mod;
            dp[i][j][3] = (dp[i-1][j+1][0] + dp[i-1][j+1][1] + dp[i-1][j+1][2]) % mod;
            dp[i][j][4] = dp[i-1][j+1][3];
        }
    }
    
    ll ans = 0;
    for (int i = 0; i <= 9; i++){
        ans += dp[n][i][0] + dp[n][i][1] + dp[n][i][2] + dp[n][i][3] + dp[n][i][4];
        ans %= mod;
    }
    
    cout << ans;
}