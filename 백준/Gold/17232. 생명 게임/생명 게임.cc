#include <bits/stdc++.h>
using namespace std;

int dp[101][101];

int main(){
    
    int n, m, t;
    cin >> n >> m >> t;
    
    int k, a, b;
    cin >> k >> a >> b;
    
    vector<string> grid(n);
    for(auto& i : grid) cin >> i;
    
    while(t--){
        
        // set dp
        for(int i = 0; i < n; i++){
            for(int j =0; j < m; j++){
                dp[i][j] = (grid[i][j] == '*');
                if (i != 0) dp[i][j] += dp[i-1][j];
                if (j != 0) dp[i][j] += dp[i][j-1];
                if (i != 0 && j != 0) dp[i][j] -= dp[i-1][j-1];
            }
        }
        
        // get next state
        vector<string> next(n, string(m, '.'));
        for (int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                int tt = -(grid[i][j] == '*');
                tt += dp[min(n-1, i+k)][min(m-1, j+k)];
                if (i - k - 1 >= 0) tt -= dp[i-k-1][min(m-1, j+k)];
                if (j - k - 1>= 0) tt -= dp[min(n-1, i+k)][j - k- 1];
                if (i - k - 1 >= 0 && j - k - 1 >= 0) tt += dp[i - k - 1][j - k - 1];
                
                if (grid[i][j] == '*'){
                    if (tt >= a && tt <= b) next[i][j] = '*';
                }
                else if (tt > a && tt <= b) next[i][j] = '*';
                    
            }
        }
        
        swap(next, grid);
        
    }
    
    for(auto i : grid) cout << i << '\n';
}