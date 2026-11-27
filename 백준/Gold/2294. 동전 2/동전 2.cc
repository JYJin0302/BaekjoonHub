#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> coin(n); 
    for(auto& i : coin) cin >> i;
    
    vector<int> dp(k+1);
    
    for (int i : coin){
        if (i<=k) dp[i] = 1;
        for (int j = i + 1; j<=k; j++){
            if (dp[j - i]) {
                if (dp[j])
                    dp[j] = min(dp[j], dp[j-i] + 1);
                else
                    dp[j] = dp[j-i] + 1;
            }
        }
    }
    if (dp[k]) cout << dp[k];
    else cout << -1;
    
    
}