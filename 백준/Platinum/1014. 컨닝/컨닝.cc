#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> A;

int dp[10][1 << 10];

bool isB(int x, int y){
    return (x & (1 << y)) > 0;
}

void solve(int a, int b){
    if (dp[a][b] != -1) return;
    
    // check valid
    bool ok = 1;
    for (int i = 0; i<m; i++){
        if (isB(b, i) && A[a][i] == 'x') ok = 0;
    }
    for(int i = 1; i < m; i++){
        if (isB(b, i) && isB(b, i-1)) ok = 0;
    }
    
    if (!ok){
        dp[a][b] = 0;
        return;
    }
    
    int cnt = 0;
    for (int i = 0 ; i< m; i++){
        if (isB(b, i)) cnt++;
    }
    
    dp[a][b] = cnt;
    if (a == 0) return;
    
    int res = 0;
    for (int i = 0; i < (1 << m); i++){
        
        solve(a-1, i);
        ok = 1;
        // check valid
        for (int j = 0; j < m-1; j++){
            if (isB(b, j) && isB(i, j+1)) ok = 0;
        }
        for(int j = 1; j < m; j++){
            if (isB(b, j) && isB(i, j-1)) ok = 0;
        }
        
        if (ok) res = max(res, dp[a-1][i]);
    }
    
    dp[a][b] += res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        
        A = vector<string> (n);
        for(auto& i : A) cin >> i;
        
        for(int i = 0; i < n; i++){
            for (int j = 0; j < (1 << m); j++){
                dp[i][j] = -1;
            }
        }
        
        int ans = 0;
        for (int j = 0; j < (1 << m); j++){
            solve(n-1, j);
            ans = max(ans, dp[n-1][j]);
        }
        cout << ans << '\n';
    }
}