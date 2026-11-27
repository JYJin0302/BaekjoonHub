#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[201][201]; // x 좌표 차이, y 좌표 차이

const ll mod = 1000007;

int main(){
    
    int w, h;
    cin >> w >> h;
    
    int tx, ty;
    cin>> tx >> ty;
    
    for (int i = 0; i <= w; i++){
        for(int j = 0; j <= h; j++){
            
            if (i == 0 || j == 0) dp[i][j] = 1;
            else{
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
                dp[i][j] %= mod;
            }
        }
    }
    
    
    cout << (dp[tx-1][ty-1] * dp[w-tx][h-ty]) % mod;
    
}