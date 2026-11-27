#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
const ll mod = 1e9+7;
ll dp[3001][3001];
    ll tmp[3001][3001];
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            char c = A[i-1][j-1];
            if (c == 'E') dp[i][j]++;
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    swap(dp, tmp);
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            char c = A[i-1][j-1];
            if (c == 'S') dp[i][j] += tmp[i][j];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    swap(dp, tmp);
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            char c = A[i-1][j-1];
            if (c == 'M') dp[i][j] += tmp[i][j];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
    
    cout << dp[n][m];
}