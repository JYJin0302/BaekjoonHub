#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()

int F[2020];
int Z[2020];
int D[2020];
int pre[2020];

int dp[2020][2020];

void solve(){
    
    string s;
    cin >> s;

    int n;
    cin >> n;

    int sn = (int)s.size();
    Z[0] = 0;
    int l = 0, r = 0;
    for(int i = 1;i < sn; i++){
        if (i <= r) Z[i] = min(r-i+1, Z[i-l]);
        while(i + Z[i] < sn && s[i+Z[i]] == s[Z[i]]) Z[i]++;
        if (i + Z[i] > r) {
            r = i + Z[i] - 1;
            l = i;
        }
    }

    F[0] = 0;
    for(int i = 1; i < sn; i++){
        int j = F[i-1];
        while(j && s[j] != s[i]) j = F[j - 1];
        if (s[j] == s[i]) F[i] = j + 1;
    }

    // for(int i =0 ; i < sn; i++) cout << F[i] << ' ';
    // cout << '\n';

    // for(int i =0 ;i < sn; i++) cout << Z[i] << ' ';
    // cout << '\n';   

    D[0] = 1;
    for(int i = 1;i <sn; i++){
        D[i]++;
        D[i + Z[i]]--;
        D[i] += D[i-1];
    }

    // for(int i =0 ; i < sn; i++) cout << D[i] << ' ';
    // cout << '\n';

    for(int i = 0; i < sn; i++){
        dp[1][i] = -10101010;
    }
    dp[1][0] = 1;
    for(int i = 2; i <= n; i++){
        for(int j = sn-1; j >= 0; j--){
            int nx = F[j];
            if (nx) dp[i-1][nx-1] = max(dp[i-1][nx-1], dp[i-1][j]);
            else dp[i][0] = max(dp[i][0], dp[i-1][j]);
            
            if (j) dp[i][j] = dp[i-1][j-1] + D[j];
            else dp[i][j] = dp[i-1][0] + D[0];
        }

        // for(int j =0 ; j < sn; j++) {
        //     if (dp[i][j] < 0) cout << "X ";
        //     else cout << dp[i][j] << ' ';
        // }
        // cout << '\n';
    }

    int ans = 0;
    for(int i =0 ; i < sn; i++) ans = max(ans, dp[n][i]);
    cout << ans << '\n';

}

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}