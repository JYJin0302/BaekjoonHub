#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> base(n);
    for(auto& i : base) cin >> i;
    
    vector<int> dp(n+1);
    for (int i = 1; i<= n; i++){
        for (int j = i; j <= n; j++)
            dp[j] = max(dp[j - i] + base[i - 1], dp[j]);
        
    }
    
    cout << dp[n];
}