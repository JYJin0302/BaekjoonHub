#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    vector<int> A(n+1);
    for (int i = 0; i < n; i++){
        
        int x;
        cin >> x;
        A[x] = i;
    }
    
    vector<int> dp(n+1);
    int ans = 1;
    dp[1] = 1;
    for (int i = 2; i <= n; i++){
        if (A[i-1] < A[i]) dp[i] = dp[i-1] + 1;
        else dp[i] = 1;
        
        ans = max(ans, dp[i]);
    }
    
    cout << n - ans;
}