#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dp[202][202][202];

int getDp(int x, int y, int z) {
    if (x > y) swap(x, y);
    if (y > z) swap(y, z);
    if (x > y) swap(x, y);

    if (dp[x][y][z] != -1) return dp[x][y][z];
    if (y == 0) return dp[x][y][z] = z;
    if (x == 0) {
        return dp[x][y][z] = z;
    }

    if ((x ^ y ^ z) == 0) {
        // losing
        int res = 0;
        for (int i = 0; i < x; i++) {
            res = max(res, x + y + z - getDp(i, y, z));
        }
        for (int i = 0; i < y; i++) {
            res = max(res, x + y + z - getDp(x, i, z));
        }
        for (int i = 0; i < z; i++) {
            res = max(res, x + y + z - getDp(x, y, i));
        }
        return dp[x][y][z] = res;
    }
    else {
        int tx = y ^ z;
        int res = 0;
        if (tx < x) {
            res = max(res, x + y + z - getDp(tx, y, z));
        }
        int ty = x ^ z;
        if (ty < y) {
            res = max(res, x + y + z - getDp(x, ty, z));
        }

        int tz = x ^ y;
        if (tz < z) {
            res = max(res, x + y + z - getDp(x, y, tz));
        }
        return dp[x][y][z] = res;
    }

}

void solve() {

    int a, b, c;
    cin >> a >> b >> c;

    int v = getDp(a, b, c);

    cout << v * 10000 << ' ' << (a + b + c - v) * 10000 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(dp, -1, sizeof(dp));

    int t = 1;
    cin >> t;
    while(t--) solve();
}