#include <bits/stdc++.h>
using namespace std;

int A[11][11];
int B[11][11];
int dp[11][11];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int h, w;
    cin >> h >> w;
    
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
        cin >> A[i][j];
    }
    for(int i = 0; i < h; i++) for(int j = 0; j < w; j++){
        cin >> B[i][j];
    }
    
    for (int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            dp[i][j] = (A[i][j] - B[i][j]) * (A[i][j] - B[i][j]);
            if (i == 0) continue;
            
            int val = 6666666;
            for (int k = max(0, j-1); k <= min(w-1, j+1); k++){
                val = min(val, dp[i-1][k]);
            }
            dp[i][j] += val;
        }
    }
    
    int ans = 6666666;
    for (int i = 0; i < w; i++){
        ans = min(ans, dp[h-1][i]);
    }
    cout << ans;
}