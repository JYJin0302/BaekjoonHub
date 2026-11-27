#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool vs[2010][2010];

void solve() {

    ll s, x, y, dx, dy;
    cin >> s >> x >> y >> dx >> dy;

    while (s + x + y + dx + dy != 0) {
        for (int i = 0; i < 2*s; i++) {
            for (int j = 0; j < 2*s; j++) vs[i][j] = 0;
        }

        int cnt = 0;
        bool inf = 0;
        ll tx = x / s % 2, ty = y / s % 2;
        vs[x % (2*s)][y % (2*s)] = 1;
        while (tx + ty != 1 || x % s == 0 || y % s == 0) {
            cnt++;
            x += dx, y += dy;
            tx = x / s % 2, ty = y / s % 2;

            if (vs[x % (2*s)][y % (2*s)]) {
                inf = 1;
                break;
            }
            vs[x % (2 * s)][y % (2 * s)] = 1;
        }

        if (inf) cout << "The flea cannot escape from black squares.\n";
        else {
            cout << "After " << cnt << " jumps the flea lands at (" << x << ", " << y << ").\n";
        }

        cin >> s >> x >> y >> dx >> dy;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}