#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> coin(n);
    for(auto& i : coin) cin >> i;
    
    vector<int> dp(k + 1);
    dp[0] = 1;
    for (int i : coin) for (int j = i; j <= k; j++){
        dp[j] += dp[j - i];
    }
    
    cout << dp[k];
    
}