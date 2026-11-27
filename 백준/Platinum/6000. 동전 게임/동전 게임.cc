#include <bits/stdc++.h>
using namespace std;

int n;
int A[2001], B[2001];
int dp[2001][2001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    
    B[0] = A[0];
    for(int i = 1; i < n; i++) B[i] = B[i-1] + A[i];
    
    for(int x = n-1; x >= 0; x--){
        for(int y = 1; y <= n; y++){
            if (x == n-1) dp[x][y] = A[x];
            else if (x == n-2) dp[x][y] = A[x] + A[x+1];
            else{
            int rem = B[n-1] - B[x] + A[x];
            int res = 0;
            int ty = min(n, y*2);
            if (x + ty >= n){
                res = rem;
            }
            else if (y == 1){
                res = rem - min(dp[x+1][y], dp[x+2][y+1]);
            }
            else{
                res = max(dp[x][y-1], rem - min(dp[x+ty][ty], dp[x+ty-1][ty-1]));
            }
            dp[x][y] = res;
            }
        }
    }
    
    cout << dp[0][1];
}