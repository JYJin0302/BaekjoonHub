#include <bits/stdc++.h>
using namespace std;

int dp[101][101];
int h[101][101];

int conn[101];

string s;
int solve(int l, int r){
    
    if (dp[l][r] != -1) return dp[l][r];
    if (l > r) return dp[l][r] = 0;
    
    int cntW = 0, cntB = 0, ans = 1e6, ansh = 1e6;
    
    for (int i = l; i <= r; i++){
        if (s[i] == '0') cntW++;
        else cntB++;
        
        if (cntW == cntB && i != r){
            int nans = solve(l, i) + solve(i+1, r);
            int nh = max(h[l][i], h[i+1][r]);
            
            if (ans >= nans){
                ans= nans;
                ansh = min(ansh, nh);
            }
        }
    }
    
    if (cntW != cntB) {
        h[l][r] = 1e6;
        return dp[l][r] = 1e6;
    }
    
    int nans = solve(l+1, r-1);
    int nh = h[l+1][r-1] + 1;
    
    nans += nh*2 + r - l;
    
    if (s[l] != s[r] && ans >= nans){
        ans= nans;
        ansh = min(ansh, nh);
    }
    
    h[l][r] = ansh;
    return dp[l][r] = ans;
}

void bt(int l, int r){
    
    if(r == l+1) {
        conn[l] = r;
        conn[r] = l;
        return;
    }
    
    int cntW = 0, cntB = 0;
    for (int i = l; i <= r; i++){
        if (s[i] == '0') cntW++;
        else cntB++;
        
        if (cntW == cntB && i != r){
            int nans = solve(l, i) + solve(i+1, r);
            int nh = max(h[l][i], h[i+1][r]);
            
            if(dp[l][r] == nans) {
                bt(l, i), bt(i+1, r);
                return;
            }
        }
    }
    
    conn[l] = r, conn[r] = l;
    bt(l+1, r-1);
    return;
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    
    cin >> s;
    
    memset(dp, -1, sizeof(dp));
    
    cout << solve(0, n-1) << '\n';
    
    bt(0, n-1);
    
    for(int i = 0; i < n; i++){
        if (conn[i] > i){
            cout << i+1 << ' ' << conn[i] + 1 << '\n';
        }
    }
}