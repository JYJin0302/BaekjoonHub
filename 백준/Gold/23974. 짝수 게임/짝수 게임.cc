#include <bits/stdc++.h>
using namespace std;

bool dp[10][2];

int main(){
    
    int n, k;
    cin >> k >> n;
    
    n %= 6;
    dp[0][0] = 1;
    dp[0][1] = 0;
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= 4; j++){
            if (i - j < 0) break;
            
            int o = j%2;
            int o1 = (i-j)%2;
            
            if (!dp[i-j][1]) dp[i][o1^o] = 1;
            if (!dp[i-j][0]) dp[i][1^o1^o] = 1;
        }
    }
    
    if (dp[n][k]) cout << "YG";
    else cout << "HS";
    
}