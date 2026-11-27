#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int C[33][33];
int dp[1 << 21][21];
void solve(){
    
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j< m;j++){
            char c;
            cin >> c;
            if (c == '1') C[i][j] = 1;
        }
    }

    int ans = 0;
    for(int i = 1; i < (1 << n); i++){
        
        int tans = 0;
        for(int j =0 ;j < n; j++){
            if (i & (1 << j)) tans -= x;
        }

        int ti = (i-1) & i;
        int ix = log2(i - ti);

        for(int j = 0 ; j< n ;j++){
            dp[i][j] = dp[ti][j] + C[ix][j];
            
            if (dp[i][j] - y >= 0) tans += dp[i][j] - y;
        }

        ans = max(ans, tans);
    }
    cout << ans << '\n';
    
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
