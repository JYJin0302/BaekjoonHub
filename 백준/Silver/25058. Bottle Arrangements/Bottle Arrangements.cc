#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair


void solve() {

    int n, m;
    cin >> n >> m;

    int r = 0, w = 0;

    while (m--) {
        int a, b;
        cin >> a >> b;
        r = max(r, a);
        w = max(w, b);
    }

    if (r + w > n) {
        cout << "IMPOSSIBLE\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i < r) cout << 'R';
        else cout << 'W';
    }
    cout << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}