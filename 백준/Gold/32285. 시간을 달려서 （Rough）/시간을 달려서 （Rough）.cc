#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


map<ll, int> dp, dp2;

void solve() {

    ll g, f;
    cin >> g >> f;

    int cnt = 0;
    ll tg = g;
    while (tg) {
        if (tg & 1) tg--;
        else tg >>= 1;
        cnt++;
    }

    queue<pair<ll, int>> q;
    dp[g] = 1;
    q.push(mp(g, 1));

    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();

        if (b == (cnt + 1) / 2 + 1) continue;
        if (!dp[a - 1]) {
            dp[a - 1] = b + 1;
            q.push(mp(a - 1, b + 1));
        }

        if (!(a & 1) && !dp[a >> 1]) {
            dp[a >> 1] = b + 1;
            q.push(mp(a >> 1, b + 1));
        }

        a += f;
        if (!(a & 1) && (a >> 1) < f && !dp[a >> 1]) {
            dp[a >> 1] = b + 1;
            q.push(mp(a >> 1, b + 1));
        }
    }

    dp2[0] = 1;
    q.push(mp(0, 1));

    while (!q.empty()) {
        auto [a, b] = q.front(); q.pop();

        if (b == cnt / 2 + 1) continue;

        ll na = (a + 1) % f;
        if (!dp2[na]) {
            dp2[na] = b + 1;
            q.push(mp(na, b + 1));
        }

        na = (a << 1) % f;
        if (!dp2[na]) {
            dp2[na] = b + 1;
            q.push(mp(na, b + 1));
        }
    }

    for (auto f : dp2) {
        if (dp[f.x]) cnt = min(cnt, dp[f.x] + f.y - 2);
    }
    cout << cnt << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}