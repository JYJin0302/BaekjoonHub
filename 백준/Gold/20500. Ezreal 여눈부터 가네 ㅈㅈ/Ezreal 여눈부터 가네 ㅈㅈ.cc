#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;

int main(){
    
    int n;
    cin >> n;
    
    vector<vector<ll>> dp(n+1,vector<ll>(3));
    
    dp[1][2] = 1;
    for(int i = 2; i<= n; i++){
        dp[i][0] = (dp[i-1][2] + dp[i-1][1]) % mod;
        dp[i][1] = (dp[i-1][0] + dp[i-1][2]) % mod;
        dp[i][2] = (dp[i-1][1] + dp[i-1][0]) % mod;
    }
    
    cout << dp[n][0];
}