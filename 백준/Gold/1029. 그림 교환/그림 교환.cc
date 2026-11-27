#include <bits/stdc++.h>
using namespace std;

int n;
string A[15];

int dp[15][1 << 15]; // 현재 가지고 있는 사람, 그림을 소유했던 사람 => 최근 매입 가격

int solve(int p, int ps){
   if (dp[p][ps] != -1) return dp[p][ps];
    
    if (((1 << p) & ps) == 0) return dp[p][ps] = 10;
    
    int ns = ps ^ (1 << p);
    int res = 10;
    
    for(int i = 0; i < n; i++){
        if (i == p || ((1 << i) & ns == 0)) continue;
        if ((A[i][p] - '0') >= solve(i, ns)) res = min(res, A[i][p] - '0');
    }
    return dp[p][ps] = res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) cin >> A[i];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n); j++) dp[i][j] = -1;
    }
    dp[0][1] = 0;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n); j++) solve(i, j);
    }
    
    int ans = 1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < (1 << n); j++) {
            if (dp[i][j] != 10){
                int cnt = 0;
                for (int k = 0; k < n; k++) cnt += ((j & (1 << k)) != 0);
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;
}