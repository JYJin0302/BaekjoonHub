#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 2;
    for (int i = 5; i <= 1000000; i++){
        dp[i] = 2;
        for (int j = 2; j*j <= i-1; j++){
            if ((i-1) % j == 0){
                dp[i] = max(dp[i], dp[(i-1)/j]+1);
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    for(int tc = 1; tc <= t;tc++){
        
        int n;
        cin >> n;
        
        int ans = 1;
        for (int i = 3; i *i <= n; i++){
            if (n % i == 0) {
                ans = max(ans, dp[n/i]);
                ans = max(ans, dp[i]);
            }
        }
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
}