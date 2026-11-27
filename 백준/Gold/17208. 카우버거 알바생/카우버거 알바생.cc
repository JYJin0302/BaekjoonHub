#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dp[301][301];
int temp[301][301];

int main(){
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<pair<int, int>> ord(n);
    for(auto& i : ord) cin >> i.x >> i.y;
    
    for (int i = 0; i < n; i++){
        int dx = ord[i].x, dy = ord[i].y;
        for (int a = 0; a <= m; a++){
            for (int b = 0; b <= k; b++){
                
                temp[a][b] = dp[a][b];
                if (a > 0) temp[a][b] = max(temp[a][b], dp[a-1][b]);
                if (b > 0) temp[a][b] = max(temp[a][b], dp[a][b-1]);
                if (a > 0 && b > 0) temp[a][b] = max(temp[a][b], dp[a-1][b-1]);
                if (a >= dx && b >= dy) temp[a][b] = max(temp[a][b], dp[a-dx][b-dy] + 1);
            }
        }
        swap(temp, dp);
    }
    
    cout << dp[m][k];
    
}