#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, x;
    cin >> n >> x;

    int res = -1;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        if (a + b > x) continue;
        res = max(res, a);
    }
    cout << res << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}