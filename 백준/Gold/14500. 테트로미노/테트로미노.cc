#include <bits/stdc++.h>
using namespace std;

int n, m;
int grid[505][505];

int T(){
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m - 2; j++){
        ans = max(ans, grid[i][j] + grid[i][j+1] + grid[i][j+2] + max(grid[i+1][j+1], grid[i-1][j+1]));
    }
    for (int i = 1; i <= n-2; i++) for (int j = 1; j <= m; j++){
        ans = max(ans, grid[i][j] + grid[i+1][j] + grid[i+2][j] + max(grid[i+1][j+1], grid[i+1][j-1]));
    }
    return ans;
}
int L(){
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m - 2; j++){
        ans = max(ans, grid[i][j] + grid[i][j+1] + grid[i][j+2] + max({grid[i+1][j], grid[i+1][j+2], grid[i-1][j], grid[i-1][j+2]}));
    }
    for (int i = 1; i <= n-2; i++) for (int j = 1; j <= m; j++){
        ans = max(ans, grid[i][j] + grid[i+1][j] + grid[i+2][j] + max({grid[i][j+1], grid[i+2][j+1], grid[i][j-1], grid[i+2][j-1]}));
    }
    return ans;
}
int I(){
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m - 3; j++){
        ans = max(ans, grid[i][j] + grid[i][j+1] + grid[i][j+2] + grid[i][j+3]);
    }
    for (int i = 1; i <= n - 3; i++) for (int j = 1; j <= m; j++){
        ans = max(ans, grid[i][j] + grid[i+1][j] + grid[i+2][j] + grid[i+3][j]);
    }
    return ans;
}
int O(){
    int ans = 0;
    for (int i = 1; i <= n - 1; i++) for (int j = 1; j <= m- 1; j++){
        ans = max(ans, grid[i][j] + grid[i+1][j] + grid[i][j+1] + grid[i+1][j+1]);
    }
    return ans;
}
int S(){
    int ans = 0;
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m - 1; j++){
        ans = max(ans, grid[i][j] + grid[i][j+1] + max(grid[i-1][j+1] + grid[i+1][j], grid[i-1][j] + grid[i+1][j+1]));
    }
    for (int i = 1; i <= n-1; i++) for (int j = 1; j <= m; j++){
        ans = max(ans, grid[i][j] + grid[i+1][j] + max(grid[i+1][j+1] + grid[i][j-1], grid[i+1][j-1] + grid[i][j+1]));
    }
    return ans;
}



int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin >> grid[i][j];
        }
    }
    
    cout << max({S(), L(), O(), T(), I()});
}