#include <bits/stdc++.h>
using namespace std;

const int mod = 9901;
int dp[201][101]; // dp[n][k] : 높이 k 이하, 노드 개수 n 인 경우의 수

int solve(int n, int k){
    
    if (dp[n][k] != -1) return dp[n][k];
    if (k == 0) return dp[n][k] = 0;
    if (n <= 1) return dp[n][k] = n;
    if (k == 1 || n % 2 == 0) return dp[n][k] = 0;
    
    //if (pow(2, k) - 1 < n || 2*k-1 > n) return dp[n][k] = 0;
    
    int res = 0;
    for (int i = 1; i <= n-2; i++){
        res += solve(i, k-1)*solve(n-1-i, k-1);
        res -= solve(i, k-2)*solve(n-1-i, k-2);
        res = (res + mod*mod) % mod;
    }
    
    return dp[n][k] = res + solve(n,k -1);
}

int main(){
    
    memset(dp, -1, sizeof(dp));
    
    int n, k;
    cin >> n >> k;
    
    dp[1][1] = 1;
    dp[1][2] = 1;
    dp[3][2] = 1;
    
    cout << solve(n, k) - solve(n, k-1);
}