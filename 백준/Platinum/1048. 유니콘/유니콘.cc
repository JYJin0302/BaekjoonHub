#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, l;
const ll mod = 1e9+7;
ll dp[301][301];
ll tmp[301][301];

string grid[301];

void fillDp(){
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            dp[i][j] += dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1];
            dp[i][j] = (dp[i][j] + mod) % mod;
        }
    }
}

ll getVal(int x, int y){
    
    ll res = 0;
    if (x > 2 && y > 2){
        res += dp[x-3][y-2] + dp[x-2][y-3] - dp[x-3][y-3];
        res = (res + mod) % mod;
    }
    
    if (x > 2 && y + 2 <= m){
        if (y + 3 <= m) {
            res += dp[x-2][m] - dp[x-2][y+2];
            res = (res + mod) % mod;
        }
        
        res += dp[x-3][y+2] - dp[x-3][y+1];
        res = (res + mod) % mod;
    }
    
    if (x + 2 <= n && y > 2){
        if (x + 3 <= n){
            res += dp[n][y-2] - dp[x+2][y-2];
            res = (res + mod) % mod;
        }
        
        res += dp[x+2][y-3] - dp[x+1][y-3];
        res = (res + mod) % mod;
        
    }
    
    if (x + 2 <= n && y + 2 <= m){
        
        res += dp[n][m] - dp[x+1][m] - dp[n][y+1] + dp[x+1][y+1];
        res = (res + 2*mod) % mod;
        
        res = (res - dp[x+2][y+2] + dp[x+1][y+2] + dp[x+2][y+1] - dp[x+1][y+1] + 2*mod) % mod;
    }
    
    return res;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m >> l;
    string path;
    cin >> path;
    l = path.size();
    
    for (int i = 0; i < n; i++){
        
        cin >> grid[i];
        
        for (int j = 0; j < m; j++){
            dp[i+1][j+1] = (grid[i][j] == path[0]);
        }
    }
    
    fillDp();
    
    for (int k = 1; k < l; k++){
        char c = path[k];
        memset(tmp, 0, sizeof(tmp));
        
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= m ;j++){
                
                if (grid[i-1][j-1] == c){
                    tmp[i][j] = getVal(i, j);
                }
                
            }
        }
        
        swap(dp, tmp);
        fillDp();
        
    }
    
    cout << dp[n][m];
}