#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int encode(char c){
    if(c >= 'A' && c <= 'Z') return c -'A'+1;
    return c - 'a' + 27;
}
int A[300];
int dp[300][300][53];

int getDp(int l, int r, int c){
    if (l > r) return 0;
    if (dp[l][r][c] != -1) return dp[l][r][c];

    if (l == r){
        if (A[l] == c) return dp[l][r][c] = 0;
        return dp[l][r][c] = 1;
    }

    if (A[l] == c) return dp[l][r][c] = getDp(l+1, r, c);
    if (A[r] == c) return dp[l][r][c] = getDp(l, r-1, c);

    int ret = 500;
    if (A[l] == A[r]){
        ret= min(ret, getDp(l+1, r-1, A[l]) + 1);
    }
    
    for(int i = l; i < r;i ++){
        ret = min(ret, getDp(l, i, c) + getDp(i+1, r, c));
    }

    return dp[l][r][c] = ret;
}



void solve(){
    
    int n;
    cin >> n;

    string s;
    cin >> s;

    for(int i =0 ; i< n; i++) A[i] = encode(s[i]);

    memset(dp, -1, sizeof dp);
    int ans = getDp(0, n-1, 0);
    cout << ans << '\n';

}



int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
