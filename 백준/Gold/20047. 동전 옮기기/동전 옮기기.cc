#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    
    string s, t;
    cin >> s >> t;
    
    int x1, x2;
    cin >> x1 >> x2;
    
    char c1 = s[x1], c2 = s[x2];
    
    s = s.substr(0, x1) + s.substr(x1+1, x2-x1-1) + s.substr(x2+1, n);
    
    bool dp[10001][3];
    dp[0][0] = (s[0] == t[0]);
    dp[0][1] = (c1 == t[0]);
    dp[0][2] = 0;
    
    for (int i =1; i < n; i++){
        
        dp[i][0] = dp[i-1][0] && (s[i] == t[i]);
        
        dp[i][1] = (dp[i-1][0] && c1 == t[i]) || (dp[i-1][1] && s[i-1] == t[i]);
        
        dp[i][2] = (dp[i-1][1] && c2 == t[i]) || (dp[i-1][2] && s[i-2] == t[i]);
    }
    
    if (dp[n-1][2]) cout << "YES";
    else cout << "NO";
}