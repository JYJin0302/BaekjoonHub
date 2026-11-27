#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[1010][3][2];  // 날, 결석, 지각
// 결석 : 3일 연속 시 X, 지각 : 2회 이상 시 X

const ll mod = 1000000;

int main(){
    
    int n;
    cin >> n;
    
    dp[1][0][0] = 1;
    dp[1][1][0] = 1;
    dp[1][0][1] = 1;
    
    
    for (int i = 2; i <= n; i++){
        // 출석
        dp[i][0][0] = (dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0]) % mod;
        dp[i][0][1] = (dp[i-1][1][1] + dp[i-1][0][1] + dp[i-1][2][1]) % mod;
        
        // 결석
        dp[i][1][0] = dp[i-1][0][0];
        dp[i][2][0] = dp[i-1][1][0];
        dp[i][1][1] = dp[i-1][0][1];
        dp[i][2][1] = dp[i-1][1][1];
        
        // 지각
        dp[i][0][1] = (dp[i][0][1] + dp[i-1][0][0] + dp[i-1][1][0] + dp[i-1][2][0]) % mod;
    }
    
    int ans = 0;
    for(int i = 0; i <3; i++){
        for (int j = 0; j < 2; j++){
            ans += dp[n][i][j];
            ans %= mod;
        }
    }
    cout << ans;
}