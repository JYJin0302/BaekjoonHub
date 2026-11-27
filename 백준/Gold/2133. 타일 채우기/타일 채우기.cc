#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n%2) {cout << 0; return 0;}
    n /= 2;
    
    vector<int> dp(16);
    dp[0] = 1;
    dp[1] = 3;
    dp[2] = 11;
    for (int i = 3; i <= n; i++){
        dp[i] += dp[i-1]*3;
        for (int j = 2; i >= j; j++)
            dp[i] += dp[i-j] * 2;
    }
    cout << dp[n];
}