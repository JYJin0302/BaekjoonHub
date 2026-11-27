#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n;
vector<int> xpos, ypos;
int xS[10101];
int yS[10101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0,1 ,0, -1 };

int getVal(int x, int y) {
    int res = 0;
    int ix = lower_bound(all(xpos), x) - xpos.begin();
    if (ix) res += ix * x - xS[ix - 1];
    if (ix < n) res += xS[n - 1] - (ix ? xS[ix - 1] : 0) - (n - ix) * x;
    ix = lower_bound(all(ypos), y) - ypos.begin();
    if (ix) res += ix * y - yS[ix - 1];
    if (ix < n) res += yS[n - 1] - (ix ? yS[ix - 1] : 0) - (n - ix) * y;
    return res;
}
void solve() {

    cin >> n;
    map<pair<int, int>, bool> vis;
    vector<pair<int, int>> A(n);

    for (auto& i : A) {
        cin >> i.x >> i.y;
        vis[i] = 1;
        xpos.push_back(i.x);
        ypos.push_back(i.y);
    }
    sort(all(xpos));
    sort(all(ypos));

    xS[0] = xpos[0];
    for (int i = 1; i < n; i++) xS[i] = xS[i - 1] + xpos[i];
    yS[0] = ypos[0];
    for (int i = 1; i < n; i++) yS[i] = yS[i - 1] + ypos[i];

    int lx, rx, ly, ry;
    if (n & 1) {
        lx = rx = xpos[n / 2];
        ly = ry = ypos[n / 2];
    }
    else {
        lx = xpos[n / 2 - 1];
        rx = xpos[n / 2];
        ly = ypos[n / 2 - 1];
        ry = ypos[n / 2];
    }

    int cnt = 0;
    for (auto [a, b] : A) {
        if (a >= lx && a <= rx && b >= ly && b <= ry) cnt++;
    }

    if (cnt != (rx - lx + 1) * (ry - ly + 1)) {
        int val = getVal(lx, ly);
        cout << val << ' ' << (rx - lx + 1) * (ry - ly + 1) - cnt << '\n';
        return;
    }

    map<int, int> res;
    for (auto [a, b] : A) {
        for (int k = 0; k < 4; k++) {
            int na = a + dx[k];
            int nb = b + dy[k];
            if (!vis[mp(na, nb)]) {
                res[getVal(na, nb)]++;
                vis[mp(na, nb)] = 1;
            }
        }
    }
    auto [a, b] = *res.begin();
    cout << a << ' ' << b << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}