#include <bits/stdc++.h>
using namespace std;

int dp[1000001];

int solve(int x){
    
    if (dp[x] != 0) return dp[x];
    
    if (x == 3) return 0;
    if (x == 4) return 1;
    if (x == 5) return 2;
    
    return dp[x] = solve(x-x/2)+2;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    cout << solve(n);
}