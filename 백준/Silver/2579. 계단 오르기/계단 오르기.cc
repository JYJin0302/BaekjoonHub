#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    
    vector<int> A(n), dp(n);
    for(auto& i :A )cin >> i;
    
    dp[0] = A[0];
    if (n > 1){
        dp[1] = A[0] + A[1];
    }
    if (n > 2) dp[2] = max(A[0], A[1]) + A[2];
    
    for (int i = 3; i < n; i++){
        dp[i] = max(dp[i-2] + A[i], dp[i-3] + A[i-1] + A[i]);
    }
    
    cout << dp[n-1];
}