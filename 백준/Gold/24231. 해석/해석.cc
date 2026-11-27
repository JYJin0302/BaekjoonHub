#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9+7;
string s;
ll dp[301][301];

ll solve(int l, int r){
    if (dp[l][r] != -1) return dp[l][r];
    if (l == r+1) return dp[l][r] = 1;
    if (l >= r) return dp[l][r] = 0;
    if (r == l+1 && s[l] != s[r]) return dp[l][r] = 1;
    
    ll ans = 0;
    if (s[l] != s[r]) ans += solve(l+1, r-1);
    
    for (int i = l+1; i < r; i+=2){
        if (s[l] != s[i]) ans = (ans + solve(l+1, i-1)*solve(i+1, r)) % mod;
    }
    
    return dp[l][r] = ans;
}

int main(){
    
    memset(dp, -1, sizeof(dp));
    cin >> s;
    
    int n= s.size();
    cout << solve(0, n-1);
}