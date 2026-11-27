#include <bits/stdc++.h>
using namespace std;

int dp[11];
int solve(int n){
    if (dp[n] != 0) return dp[n];
    if (n == 1) return dp[n] = 0;
    int a = n/2, b = n - a;
    return dp[n] = a*b + solve(a) + solve(b);
}

int main(){
    int n;
    cin >> n;
    
    cout << solve(n);
}