#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    vector<int>A(n), dp(n);
    for(auto& i : A) cin >> i;
    
    dp[0] = A[0];
    for(int i = 1; i < n; i++){
        for (int j = 0; j < i; j++){
            if (A[j] > A[i]) dp[i] = max(dp[i], dp[j]);
        }
        dp[i] += A[i];
    }
    
    cout << *max_element(dp.begin(), dp.end());
}