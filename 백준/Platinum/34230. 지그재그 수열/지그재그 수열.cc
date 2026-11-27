#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int dp[5050][5050][2];
 
void solve() {
 
    int n;
    cin >> n;
 
    vector<int> A(n + 1);
    for(int i = 1; i <= n; i++) cin >> A[i];

    memset(dp, -1, sizeof dp);

    for(int i = 0 ;i <= 4095; i++){
        dp[0][i][0] = dp[0][i][1] = 0;
    }

    // 0 : low, 1 : high
    for(int i = 1; i <= n; i++){
        int v = 0;
        for(int j = i; j >= 1; j--){
            v ^= A[j];

            if (j == 1){
                dp[i][v][0] = max(dp[i][v][0], 1);
                dp[i][v][1] = max(dp[i][v][1], 1);
            }

            if (v < 4096 && dp[j-1][v+1][1] != -1) dp[i][v][0] = max(dp[i][v][0], dp[j-1][v+1][1] + 1);
            if (v && dp[j-1][v-1][0] != -1) dp[i][v][1] = max(dp[i][v][1], dp[j-1][v-1][0] + 1);
        }

        for(int j = 1; j <= 4095; j++){
            dp[i][j][0] = max(dp[i][j][0], dp[i][j-1][0]);
        }
        for(int j = 4094; j >= 0; j--){
            dp[i][j][1] = max(dp[i][j][1], dp[i][j+1][1]);
        }

        // for(int j = 0 ;j <= 3; j++){
        //     cout << dp[i][j][0] << ' ' << dp[i][j][1] << " | ";
        // }
        // cout << '\n';
    }

    int ans = max(dp[n][0][1], dp[n][4095][0]);
    cout << n - ans << '\n';
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