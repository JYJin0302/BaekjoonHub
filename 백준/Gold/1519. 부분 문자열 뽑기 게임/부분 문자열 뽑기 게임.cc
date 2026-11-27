#include <bits/stdc++.h>
using namespace std;

int dp[1000001];
int solve(int x){
    if (dp[x] != -1) return dp[x];
    if (x <= 9) return dp[x] = -1;
    
    string s = to_string(x);
    int n = s.size();
    
    int ans = 1000000;
    for(int i = 0; i < n; i++){
        for (int j = i; j < n; j++){
            int nx = x - stoi(s.substr(i, j-i+1));
            if (nx != 0 && nx != x && solve(nx) == -1) ans = min(ans, x - nx);
        }
    }
    if (ans != 1000000) return dp[x] = ans;
    return dp[x] = -1;
}


int main(){
    
    int n;
    cin >> n;
    
    memset(dp, -1, sizeof(dp));
    cout << solve(n);
    
}