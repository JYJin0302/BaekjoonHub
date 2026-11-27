#include <bits/stdc++.h>
using namespace std;

int dp[205][205];

const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    while(n){
        
        int s, t;
        cin >> s >> t;
        
        vector<int> A(n+2);
        for(int i = 1; i <= n; i++) cin >> A[i];
        
        for (int i = 0; i <= t; i++){
            for (int j = 0; j <= n+1; j++){
                dp[i][j] = -INF;
            }
        }
        
        dp[0][0] = 0;
        for (int i = 1; i <= t; i++){
            for (int x = 1; x <= n + 1; x++){
                for (int d = 1; d <= s; d++){
                    if (x - d >= 0 && dp[i-1][x-d] != -INF) dp[i][x] = max(dp[i][x], dp[i-1][x-d] + A[x]);
                }
            }
        }
        
        int ans = -INF;
        for (int i = 1; i <= t; i++){
            ans = max(ans, dp[i][n+1]);
        }
        cout << ans << '\n';
        
        
        cin >> n;
    }
}