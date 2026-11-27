#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    bool ok = 0;

    vector<pair<int, int>> vis;
    int cx = 0, cy = 0;
    for (auto f : s) {
        if (f == 'U') cy++;
        else if (f == 'D') cy--;
        else if (f == 'R') cx++;
        else cx--;

        vis.push_back(mp(cx, cy));
        if (cx == 0 && cy == 0) ok = 1;
    }

    if (ok) {
        cout << "YES\n";
        return;
    }
    k--;

    int dx = vis.back().first, dy = vis.back().second;
    for (auto& [a, b] : vis) {

        int v1 = -1, v2 = -1;
        if (dx != 0) {
            v1 = a / -dx;
            if (a % -dx != 0) continue;
        }
        else if (a != 0) continue;

        if (dy != 0) {
            v2 = b / -dy;
            if (b % -dy != 0) continue;
        }
        else if (b != 0) continue;

        if (dx == 0) v1 = v2;
        else if (dy == 0) v2 = v1;

        if (v1 == v2 && v1 >= 0 && v1 <= k) {
            ok = 1;
        }
    }
    if (ok) cout << "YES\n";
    else cout << "NO\n";


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while(t--) solve();
}