#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    int n;
    cin >> n;
    
    vector<ll> dp(91);
    dp[1] = 1;
    dp[2] = 1;
    for (int i = 3; i < 91; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    cout << dp[n];
}