#include <bits/stdc++.h>
using namespace std;

int dp[10001][101];

int op(int x, int i){
    x += pow(10, i);
    if ((x % (int)pow(10, i+1)) < pow(10, i)) x -= pow(10, i+1);
    return x;
}

int n, m;
int solve(int x, int t){
    
    if (dp[x][t] != -1) return dp[x][t];
    if (t == 0) return dp[x][t] = x;
    
    int r = 0;
    if ((m - t) % 2 == 0){
        for(int i = 0; i < 4; i++){
            int tx = op(x, i);
            r = max(r, solve(tx, t-1));
        }
    }
    else{
        r = 10000;
        for(int i = 0; i < 4; i++){
            int tx = op(x, i);
            r = min(r, solve(tx, t-1));
        }
    }
    return dp[x][t] = r;
}
int main(){    
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> m;
    
    for(int i = 0; i < 10000; i++) {
        for(int j = 0; j <= 100; j++){
            dp[i][j] = -1;
        }
    }
    
    if (solve(n, m) > n) cout << "koosaga";
    else cout << "cubelover";
    
}