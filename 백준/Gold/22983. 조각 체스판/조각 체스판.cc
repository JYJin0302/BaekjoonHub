#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dp[3001][3001][2];
// 0 : white, 1 : black

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    ll n, m;
    cin >> n >> m;
    
    vector<string> A(n);
    for(auto& i : A) cin >> i;
    
    ll ans = 0;
    
    for(int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            
            if (A[i-1][j-1] == 'W'){
                dp[i][j][0] = min({dp[i-1][j-1][0], dp[i-1][j][1], dp[i][j-1][1]}) + 1;
                dp[i][j][1] = 0;
            }
            else{
                dp[i][j][0] = 0;
                dp[i][j][1] = min({dp[i-1][j-1][1], dp[i-1][j][0], dp[i][j-1][0]}) + 1;;
            }
            
            ans += dp[i][j][0] + dp[i][j][1];
        }
    }
    
    cout << ans;
}