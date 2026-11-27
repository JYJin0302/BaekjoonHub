#include <bits/stdc++.h>
using namespace std;



int dp[201][201];
int mod = 1e9;


int main(){
    int n, k;
    cin >> n >>k;
    for (int i = 1; i <= 200; i ++){
        dp[0][i] =1;
    }
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= k; j++){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%mod;
        }
    }
    
    cout << dp[n][k];
}