#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int dx[] = { 0, 0, 1, 0, -1 };
int dy[] = { 0, -1, 0, 1, 0 };

ll dp[100001][5];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<pair<ll, ll>> A(n + 1);
    for (auto& i : A) cin >> i.x >> i.y;

    for (int i = 1; i <= n; i++) {

        if (i == 1) {

            for (int k = 0; k < 5; k++) {
                int nx = A[i].x + dx[k];
                int ny = A[i].y + dy[k];

                dp[i][k] = abs(nx - A[i - 1].x) + abs(ny - A[i - 1].y);
            }
        }
        else {
            
            for (int k = 0; k < 5; k++) {
                dp[i][k] = 1e15;

                ll nx = A[i].x + dx[k];
                ll ny = A[i].y + dy[k];

                for (int w = 0; w < 5; w++) {

                    ll tx = A[i-1].x + dx[w];
                    ll ty = A[i-1].y + dy[w];

                    dp[i][k] = min(dp[i][k], dp[i-1][w] + abs(nx - tx) + abs(ny - ty));
                }
            }
        }
    }


    ll ans = 1e15;
    for (int i = 0; i < 5; i++) {
        ans = min(ans, dp[n][i]);
    }
    cout << ans;
}