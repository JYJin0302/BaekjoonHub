#include <bits/stdc++.h>
using namespace std;
using ll = long long;
 
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int G[1010][1010];
array<int, 3> dp[1010][1010];

bool chk(array<int, 3>& c){
    return (1<<c[0]) + (1<<c[1]) + (1<<c[2]) == 14;
}
void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    map<char, int> cx;
    cx['E'] = 0;
    cx['W'] = 1;
    cx['F'] = 2;
    cx['A'] = 3;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m;j++){
            char c;
            cin >> c;
            G[i][j] = cx[c];
        }
    }

    int ans = 0;
    for(int i = 1; i < n; i++){
        for(int j = 1; j < m; j++){
            dp[i][j][0] = G[i][j+1] ^ G[i][j];
            dp[i][j][1] = G[i+1][j] ^ G[i][j];
            dp[i][j][2] = G[i+1][j+1] ^ G[i][j];

            ans += chk(dp[i][j]);
        }
    }

    cout << ans << '\n';
    while(q--){
        int t, x1, y1, x2, y2;
        cin >> t >> x1 >> y1 >> x2 >> y2;

        t = 3 - t;
        // edge
        if (x1 > 1){
            for(int j = y1; j < y2; j++){
                ans -= chk(dp[x1-1][j]);
                dp[x1-1][j][1] ^= t;
                dp[x1-1][j][2] ^= t;
                ans += chk(dp[x1-1][j]);
            }
        }

        if (x2 < n){
            for(int j = y1; j < y2; j++){
                ans -= chk(dp[x2][j]);
                dp[x2][j][1] ^= t;
                dp[x2][j][2] ^= t;
                ans += chk(dp[x2][j]);
            }
        }

        if (y1 > 1){
            for(int i = x1; i < x2; i++){
                ans -= chk(dp[i][y1-1]);
                dp[i][y1-1][0] ^= t;
                dp[i][y1-1][2] ^= t;
                ans += chk(dp[i][y1-1]);
            }
        }

        if (y2 < m){
            for(int i = x1; i < x2; i++){
                ans -= chk(dp[i][y2]);
                dp[i][y2][0] ^= t;
                dp[i][y2][2] ^= t;
                ans += chk(dp[i][y2]);
            }
        }

        // corner
        if (x1 > 1 && y1 > 1){
            ans -= chk(dp[x1-1][y1-1]);
            dp[x1-1][y1-1][2] ^= t;
            ans += chk(dp[x1-1][y1-1]);
        }

        if(x1 > 1 && y2 < m){
            ans -= chk(dp[x1-1][y2]);
            dp[x1-1][y2][1] ^= t;
            ans += chk(dp[x1-1][y2]);
        }

        if (x2 < n && y1 > 1){
            ans -= chk(dp[x2][y1-1]);
            dp[x2][y1-1][0] ^= t;
            ans += chk(dp[x2][y1-1]);
        }

        if (x2 < n && y2 < m){
            ans -= chk(dp[x2][y2]);
            dp[x2][y2][0] ^= t;
            dp[x2][y2][1] ^= t;
            dp[x2][y2][2] ^= t;
            ans += chk(dp[x2][y2]);
        }

        cout << ans << '\n';

        // for(int i = 1; i < n; i++){
        //     for(int j = 1; j < m;j++){
        //         cout << chk(dp[i][j]) << ' ';
        //     }
        //     cout << '\n';
        // }
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}