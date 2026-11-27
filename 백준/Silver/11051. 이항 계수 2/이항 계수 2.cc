#include <bits/stdc++.h>
using namespace std;

int dp[1001][1001];

int cal(int n, int k){
    if (n == k || k == 0) return 1;
    if (dp[n][k]) return dp[n][k];
    
    int t = (cal(n-1, k)  + cal(n-1, k-1)) % 10007;
    dp[n][k] = t;
    return t;
}




int main(){
    int n, k;
    cin >> n >> k;
    
    cout << cal(n, k);
}