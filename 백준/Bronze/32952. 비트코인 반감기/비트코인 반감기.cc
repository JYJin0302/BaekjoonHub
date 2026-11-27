#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    ll r, m, k;
    cin >> r >> m >> k;

    ll cur = 0, val = r;
    while (val> 0 && cur + m <= k) {
        cur += m;
        val >>= 1;
    }
    cout << val << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}