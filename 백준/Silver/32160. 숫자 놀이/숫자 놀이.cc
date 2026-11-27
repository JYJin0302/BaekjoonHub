#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    int t = (n - 1) % 4;

    if (t == 0) {
        cout << n << '\n';

        for (int i = 1; i < n; i += 2) {
            cout << i << ' ' << i + 1 << '\n';
        }
        for (int i = 1; i < n/2; i++) {
            cout << i % 2 << ' ' << 1 << '\n';
        }
        cout << 0 << ' ' << n << '\n';
        return;
    }

    if (t == 3) {
        cout << n << '\n';

        for (int i = 3; i <= n; i += 2) {
            cout << i - 1 << ' ' << i << '\n';
        }
        for (int i = 1; i < n / 2; i++) {
            cout << i % 2 << ' ' << 1 << '\n';
        }
        cout << 0 << ' ' << n << '\n';
        return;
    }

    if (t == 1) {
        cout << n - 1 << '\n';

        for (int i = 3; i <= n; i += 2) {
            cout << i - 1 << ' ' << i << '\n';
        }
        for (int i = 1; i < n / 2; i++) {
            cout << i % 2 << ' ' << 1 << '\n';
        }
        cout << 1 << ' ' << n << '\n';
        return;
    }


    // t == 2
    cout << n - 1 << '\n';

    for (int i = 2; i < n; i += 2) {
        cout << i - 1 << ' ' << i << '\n';
    }
    for (int i = 1; i < n / 2; i++) {
        cout << i % 2 << ' ' << 1 << '\n';
    }
    cout << 1 << ' ' << n << '\n';
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}