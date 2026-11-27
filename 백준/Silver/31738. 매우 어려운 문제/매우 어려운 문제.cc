#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, m;
    cin >> n >> m;

    if (n >= m) {
        cout << 0;
        return;
    }

    ll res = 1;
    for (int i = 1; i <= n; i++) {
        res = res * i % m;
    }
    cout << res;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}