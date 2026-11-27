#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;
ll dp[260][260];
// dp[a][b] : 길이 : a, bitwise 값 : b 인 경우의 수


int main(){
    
    int n;
    cin >> n;
    
    dp[0][0] = 1;
    dp[1][0] = 1, dp[1][1] = 1;
    
    for (int i = 2; i <= n; i++){
        dp[i][i]++;
        for (int j = 0; j < 256; j++){
            if (j+1 > i) break;
            for (int k = 0; k < 256; k++){
                dp[i][k^j] += dp[i-1-j][k];
                dp[i][k^j] %= mod;
            }
        }
    }
    
    cout << dp[n][0];
}