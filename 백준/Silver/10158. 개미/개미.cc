#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m, x, y, t;
    cin >> n >> m >> x >> y >> t;

    int nx = (x + t) % (2 * n);
    if (nx > n) nx = 2 * n - nx;

    int ny = (y + t) % (2 * m);
    if (ny > m) ny = 2 * m - ny;
    
    cout << nx << ' ' << ny << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}