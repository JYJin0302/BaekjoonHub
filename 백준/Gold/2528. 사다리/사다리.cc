#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, l;
    cin >> n >> l;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    int t = 0, pos = 0;
    while (pos < n - 1) {
        if (A[pos].first == l || A[pos + 1].first == l) {
            pos++;
            continue;
        }

        int len1 = A[pos].first;
        int dir1 = A[pos].second;
        int tt = t % (2 * (l - len1));
        if (tt >= l - len1) {
            tt -= l - len1;
            dir1 ^= 1;
        }
        int x1, x2;
        if (dir1 == 0) {
            x1 = tt;
            x2 = x1 + len1;
        }
        else {
            x2 = l - tt;
            x1 = x2 - len1;
        }

        int len2 = A[pos + 1].first;
        int dir2 = A[pos + 1].second;

        tt = t % (2 * (l - len2));
        if (tt >= l - len2) {
            tt -= l - len2;
            dir2 ^= 1;
        }

        int y1, y2;
        if (dir2 == 0) {
            y1 = tt;
            y2 = tt + len2;
        }
        else {
            y2 = l - tt;
            y1 = y2 - len2;
        }

        int dt = 0;
        while (1) {
            int tx = max(y1, x1);
            int ty = min(y2, x2);
            if (tx <= ty) break;
            dt++;

            if (dir1 == 0 && x2 == l) {
                dir1 = 1;
            }
            else if (dir1 == 1 && x1 == 0) dir1 = 0;
            if (dir1) x1--, x2--;
            else x1++, x2++;

            if (dir2 == 0 && y2 == l) {
                dir2 = 1;
            }
            else if (dir2 == 1 && y1 == 0) dir2 = 0;
            if (dir2) y1--, y2--;
            else y1++, y2++;
        }
        t += dt;
        pos++;
    }
    cout << t << '\n';
    
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}