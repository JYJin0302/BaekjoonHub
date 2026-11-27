#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int a, b, d, n;
    cin >> a >> b >> d >> n;
    
    // dp[x] : x일 째 태어나는 짚신벌레 수
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[a] = 1;
    for(int i = a+1; i <= n; i++){
        dp[i] = dp[i-1];
        if (i - a >= 0) dp[i] += dp[i-a];
        if (i - b >= 0) dp[i] -= dp[i-b];
        dp[i] = (dp[i] + 1000) % 1000;
    }
    
    int ans = 0;
    for(int i = 0; i < d; i++){
        if (n-i < 0) break;
        ans += dp[n-i];
        ans %= 1000;
    }
    cout << ans;
}