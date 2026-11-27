#include <bits/stdc++.h>
using namespace std;

int n, t;
int dp[101][20005]; 
// 0~9999 : -10000 ~ -1
// 10000 : 0
// 10001 ~ 20000 : 1 ~ 10000

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n >> t;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j <= 20000; j++) dp[i][j] = -20000;
    }
    
    dp[0][A[0] + 10000] = A[0];
    dp[1][A[0] - A[1] + 10000] = -A[1];
    for(int i = 2; i < n; i++){
        int x = A[i];
        for(int j = 0; j <= 20000; j++){
            if (j - x >= 0 && dp[i-1][j-x] != -20000){
                dp[i][j] = x;
            }
            if (j + x <= 20000 && dp[i-1][j+x] != -20000){
                dp[i][j] = -x;
            }
        }
    }
    
    vector<bool> pos(n);
    
    int x = t+10000;
    int ix = n-1;
    while(ix >= 0){
        pos[ix] = (dp[ix][x] > 0);
        x -= dp[ix][x];
        ix--;
    }
    
    int tx, cnt;
    tx = 2;
    while(tx < n){
        while(tx < n && pos[tx]) {
            cout << 2 << '\n';
            tx++;
        }
        cout << 1 << '\n';
        tx++;
    }
    if (!pos[n-1]) cout << 1;
}