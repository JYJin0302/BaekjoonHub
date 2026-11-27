#include <bits/stdc++.h>
using namespace std;

const int mod = 42043;

int dp[17][1005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, k, t;
    cin >> n >> k >> t;
    
    while(t--){
       int x;
        cin >> x;
        dp[0][x]++;
    }
    
    // set dp
    for(int i = 1; i <= 16; i++){
        for (int j = 0; j <= k; j++){
            for (int x = 0; x <= j; x++){
                dp[i][j] += dp[i-1][x] * dp[i-1][j-x];
                dp[i][j] %= mod;
            }
        }
    }
    
    int ans[1005];
    int tmp[1005];
    n--;
    for (int i = 0; i <= k; i++) ans[i] = dp[0][i];
    
    for (int i = 0; i <= 16; i++){
        bool ok = (n & (1 << i)) != 0;
        if (ok){
            for (int j = 0; j <= k; j++){
                tmp[j] = 0;
            for (int x = 0; x <= j; x++){
                tmp[j] += ans[x] * dp[i][j-x];
                tmp[j] %= mod;
            }
        }
            
         swap(ans, tmp);
        }
    }
    
    int res=  0;
    for(int i = 0; i <= k; i++) res = (res + ans[i]) % mod;
    cout << res;
    
}