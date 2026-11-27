#include <bits/stdc++.h>
using namespace std;

int dp[5001][5001];

int main(){
    
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            
            dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (s[i - 1] == s[n - j]){
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
            }
        }
    }
    
    cout << n - dp[n][n];
    
}