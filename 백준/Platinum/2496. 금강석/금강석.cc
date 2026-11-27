#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, m, t, k;
    cin >> n >> m >> t >> k;

    vector<pair<int, int>> A(t);
    vector<int> xp, yp;
    for (auto& i : A) {
        cin >> i.first >> i.second;

        for (int j = -k; j <= k; j += k) {
            for (int f = -1; f <= 1; f++) {
                xp.push_back(i.first + i.second + j + f);
                yp.push_back(i.first - i.second + j + f);
            }
        }
    }

    sort(all(xp));
    xp.erase(unique(all(xp)), xp.end());
    sort(all(yp));
    yp.erase(unique(all(yp)), yp.end());

    pair<int, pair<int, int>> ans = mp(0, mp(n / 2, m / 2));
    for (int i = 0; i < xp.size(); i++) {
        for (int j = 0; j < yp.size(); j++) {

            int v1 = xp[i];
            int v2 = yp[j];

            // x + y = v1
            // x - y = v2

            int tx = (v1 + v2) / 2;
            int ty = v1 - tx;
            tx += k / 2;

            if ((v1 + v2) % 2 != 0) continue;
            if (tx > n) tx = n;
            if (tx < 0)tx = 0;
            if (ty > m) ty = m;
            if (ty < 0) ty = 0;

            int cnt = 0;
            for (int f = 0; f < t; f++) {
                auto& [a, b] = A[f];
                if (abs(a - tx) + abs(b - ty) <= k/2) {
                    cnt++;
                }
            }

            ans = max(ans, mp(cnt, mp(tx, ty)));
           // cout << "test: " << v1 << ' ' << v2 << " | " << tx << ' '<< ty << " = " << cnt << '\n';
        }
    }

    int a, b;
    tie(a, b) = ans.second;
    cout << a << ' ' << b << '\n' << ans.first << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}