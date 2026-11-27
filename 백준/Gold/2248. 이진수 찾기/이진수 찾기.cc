#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll dp[32][32]; // dp[a][b] : a자리이고 비트가 b개 이하인 이진수의 개수

int main(){
    
    ll n, l, I;
    cin >> n >> l >> I;
    I--;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= i; j++){
            if (i == 1) dp[i][j] = 1;
            else dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
        }
    }
    
    dp[0][0] = 1;
    dp[0][1] = 1;
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] += dp[i][j-1];
        }
    }
    string ans = "";
    for (ll j = n-1; j >= 0; j--){
        if (dp[j][l] <= I){
            I -= dp[j][l];
            ans += '1';
            l--;
        }
        else ans += '0';
        l = min(j, l);
    }
    
    cout << ans;
    
}