#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

const int mod = 1e9 + 7;

ll dp[1010][1010];


void solve(){
    
    int n, m;
    cin >> n >> m;
    vector<int> A(n);
    for(auto& i :A) cin >> i;
    sort(all(A));

    vector<int> pre(n+1);
    for(int i= 1; i <= n; i++){
        if (i > 1 && A[i-2] == A[i-1]) pre[i] = pre[i-1];
        else pre[i] = i;
    }

    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        int pi = pre[i] - 1;

        for(int j = 1; j <= m; j++){
            dp[i][j] = dp[pi][j-1] * A[i-1] % mod;
        }
        for(int j = 0; j <= m;j++){
            dp[i][j] = (dp[i][j] + dp[i-1][j]) % mod;
        }
    }
    cout << dp[n][m] <<'\n';
}

 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}