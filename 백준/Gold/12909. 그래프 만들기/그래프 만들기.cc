#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    vector<int> A(n);
    for(int i = 1; i < n; i++) cin >> A[i];
    
    // n개의 차수의 합 -> 2n-2
    // dp[x][y][z] : x까지의 수에 y개를 사용 , 차수의 합z일 때의 점수 최댓값
    
    const int INF = 1e9;
    
    int dp[52][52][106];
    for (int i = 0; i <= 51; i++){
        for (int j = 0; j <= 51; j++){
            for (int k = 0; k <= 105; k++){
                dp[i][j][k] = -INF;
            }
        }
    }
    dp[0][0][0] = 0;
    
    for (int i = 1; i < n; i++){
        
        int x = A[i];
        
        for (int j = 1; j <= n; j++){
            for (int k = i; k <= n*2-2; k++){
                int c = 1;
                while(j >= c && k >= i*c){
                    dp[i][j][k] = max({dp[i][j][k], dp[i-1][j-c][k-i*c] + c*x, dp[i-1][j][k]});
                    c++;
                }
            }
        }
    }
    
    cout << dp[n-1][n][n*2-2];
}