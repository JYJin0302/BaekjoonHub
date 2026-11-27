#include <bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin >> n;
    
    vector<int> d(n);
    vector<int> w(n);
    for (int i = 0; i < n; i++){
        cin >> d[i] >> w[i];
    }
    
    vector<int> dp(n+1);
    for (int i = 0; i < n; i++){
        for (int j = i + d[i]; j <= n; j++)
            dp[j] = max(dp[j], dp[i] + w[i]);
    }
    
    
    cout << dp[n];
}