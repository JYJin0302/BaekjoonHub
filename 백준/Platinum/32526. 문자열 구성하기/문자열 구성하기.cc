#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, k;
    cin >> n >> k;

    if (k == 1) {
        cout << "Yes\n";
        cout << 'a' << string(n - 1, 'b') << '\n';
        return;
    }

    if (k == n - 1) {
        cout << "Yes\n";
        cout << string(n, 'a') << '\n';
        return;
    }

    if (k == 0) {
        if (n == 2) cout << "No\n";
        else {
            cout << "Yes\n";
            for (int i = 0; i < n; i++) cout << char('a' + i % 26);
            cout << '\n';
        }
        return;
    }

    if (n % k == 0) {
        cout << "Yes\n";
        for (int i = 0; i < k; i++) {
            cout << string(n / k - 1, 'a') << 'b';
        }
        cout << '\n';
        return;
    }

    if (n % (k + 1) == 0 && 2 * (k + 1) != n) {
        cout << "Yes\n";
        for (int i = 0; i < k + 1; i++) {
            cout << 'a' << string(n / (k + 1) - 2, 'b') << 'a';
        }
        cout << '\n';
        return;
    }
    cout << "No\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}