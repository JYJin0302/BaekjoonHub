#include <bits/stdc++.h>
using namespace std;

int dp[222];
int solve(int x){
    if (dp[x] != -1) return dp[x];
    if (x <= 2) return dp[x] = 0;
    
    vector<int> cnt(13);
    for (int i = 2; i <= (x+1)/2; i++){
        int tx = solve(i-1) ^ solve(x-i);
        if (tx <= 12) cnt[tx]++;
    }
    int r = 0;
    while(cnt[r]) r++;
    return dp[x] = r;
}

int main(){
    memset(dp, -1, sizeof(dp));
    
    int n, m;
    cin >> n >> m;
    
    if (n > 209) n = (n % 102) + 102;
    if (m > 209) m = (m % 102) + 102;
    
    int x = 0;
    x += solve(n) + solve(m);
    
    if (x == 0) cout << "hs";
    else cout << "sh";
}