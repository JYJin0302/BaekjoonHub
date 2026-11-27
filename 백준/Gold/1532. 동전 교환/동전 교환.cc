#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int g1, s1, b1, g2, s2, b2;
    cin >> g1 >> s1 >> b1 >> g2 >> s2 >> b2;

    g1 -= g2;
    s1 -= s2;
    b1 -= b2;

    int ans = 0;
    if (g1 < 0) {
        s1 -= 11 * -g1;
        ans += -g1;
        g1 = 0;
    }

    if (b1 < 0) {
        int cnt = (-b1 + 8) / 9;
        ans += cnt;
        s1 -= cnt;
        b1 += cnt * 9;
    }

    if (s1 < 0) {

        int cnt = min(g1, (-s1 + 8) / 9);
        ans += cnt;
        g1 -= cnt;
        s1 += 9 * cnt;
    }

    if (s1 < 0) {

        int cnt = min(b1, -s1 * 11);
        ans += cnt/11;
        b1 -= cnt;
        s1 += cnt/11;

    }

    if (s1 < 0) cout << -1;
    else cout << ans;


}