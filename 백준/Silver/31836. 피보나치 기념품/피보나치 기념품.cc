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

    if (n % 3 == 0) {
        cout << n / 3 << '\n';
        for (int i = 1; i <= n; i++) {
            if (i % 3 == 0) cout << i << ' ';
        }
        cout << '\n';
        cout << n - n / 3 << '\n';
        for (int i = 1; i <= n; i++) {
            if (i % 3) cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    if (n % 3 == 2) {
        cout << n / 3 + 1 << '\n' << 1 << ' ';
        for (int i = 3; i <= n; i++) {
            if (i % 3 == 2) cout << i << ' ';
        }
        cout << '\n';
        cout << n - (n / 3 + 1) << '\n' << 2 << ' ';
        for (int i = 3; i <= n; i++) {
            if (i % 3 != 2) cout << i << ' ';
        }
        cout << '\n';
        return;
    }

    // 4, 7, 10, ..

    cout << n - 1 - n / 3 << '\n';
    for (int i = 2; i <= n; i++) {
        if (i % 3 != 1) cout << i << ' ';
    }
    cout << '\n';
    cout << n / 3 << '\n';
    for (int i = 2; i <= n; i++) {
        if (i % 3 == 1) cout << i << ' ';
    }
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}