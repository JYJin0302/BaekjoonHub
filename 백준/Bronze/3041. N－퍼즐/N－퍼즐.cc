#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

char G[4][4];

void solve() {

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> G[i][j];
        }
    }
    int ans = 0;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (G[i][j] != '.') {

                int v = G[i][j] - 'A';
                int ti = v / 4;
                int tj = v % 4;
                ans += abs(ti - i) + abs(tj - j);
            }
        }
    }
    cout << ans << '\n';
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}