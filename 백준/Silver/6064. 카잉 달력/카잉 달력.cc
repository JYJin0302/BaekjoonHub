#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {

        int m, n, x, y;
        cin >> m >> n >> x >> y;

        if (x > y) {
            swap(x, y);
            swap(m, n);
        }

        int tx = (y - 1) % m + 1;
        int cnt = 0;
        int year = y;
        bool ok = false;
        while (cnt < m) {

            if (tx == x) {
                ok = true;
                break;
            }
            year += n;
            tx = (tx + n - 1) % m + 1;
            cnt++;
        }

        if (ok) cout << year << '\n';
        else cout << -1 << '\n';

    }
}