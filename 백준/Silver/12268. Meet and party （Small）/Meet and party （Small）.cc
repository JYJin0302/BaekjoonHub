#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {

        int n;
        cin >> n;

        vector<pair<ll, ll>> A;
        for (int f = 0; f < n; f++) {
            ll x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;

            for (int tx = x1; tx <= x2; tx++) {
                for (int ty = y1; ty <= y2; ty++) {
                    A.push_back(mp(tx, ty));
                }
            }
        }

        pair<ll ,pair<ll, ll>> ans= mp(1e18, mp(0, 0));
        for (auto [a, b] : A) {
            ll val = 0;
            for (auto [x, y] : A) {
                val += abs(x - a) + abs(y - b);
            }
            if (ans.x > val) {
                ans = mp(val, mp(a, b));
            }
            else if (ans.x == val) {
                ans.y = min(ans.y, mp(a, b));
            }
        }

        cout << "Case #" << i << ": " << ans.y.x << ' ' << ans.y.y << ' ' << ans.x << '\n';
    }
}