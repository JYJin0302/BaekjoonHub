#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

bool dp[501][5001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t, n;
    cin >> t >> n;
    vector<int> A(n);
    for(auto& i : A) cin >> i;
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++){
        int x = A[i-1];
        
        for (int j = 0; j <= t; j++){
            dp[i][j] = dp[i-1][j];
            if (j >= x) dp[i][j] |= dp[i-1][j-x];
        }
        
    }
    
    int ti = n, tj = t;
    while(!dp[ti][tj]) tj--;
    vector<bool> used(n);
    
    while(ti > 0){
        
        while(ti > 0 && dp[ti-1][tj]) ti--;
        
        if (!ti) break;
        
        used[ti-1] = 1;
        tj -= A[ti-1];
    }
    
    vector<int> ans(n);
    int v1 = 0, v2 = 0;
    
    for(int i = 0; i < n; i++){
        
        if (used[i]) {
            ans[i] = v1;
            v1 += A[i];
        }
        else {
            ans[i] = v2;
            v2 += A[i];
        }
    }
    
    for(int i : ans) cout << i << ' ';
    cout << '\n';
}