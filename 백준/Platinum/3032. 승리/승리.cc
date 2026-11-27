#include <bits/stdc++.h>
using namespace std;

int n;
int dp[101][101];
int A[101];

int solve(int l, int r){
    
    bool p;
    if (r > l) p = (r - l) % 2;
    else p = (r + n - l) % 2;
    
    if (dp[l][r] != -1001) return dp[l][r];
    if (l == r){
        if (!p) return dp[l][r] = -1 * A[l];
        return dp[l][r] = A[l];
    }
    
    int nl = (l + n-1) % n;
    int nr = (r + 1) % n;
    
    if (p) return dp[l][r] = max(A[l] + solve(nl, r), A[r] + solve(l, nr));
    return dp[l][r] = min(-1*A[l] + solve(nl, r), -1*A[r] + solve(l, nr));
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] %= 2;
    }
    
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            dp[i][j] = -1001;
        }
    }
    
    int ans = 0;
    for(int i = 0; i < n; i++){
        int l = (i + n-1) % n;
        int r = (i+1)%n;
        ans += (A[i] + solve(l, r) > 0);
    }
    cout << ans;
}