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
    string s;
    cin >> s;
    int ix = 0, nx = 0;
    ll ans = 0;
    while (ix < n) {

        while (ix < n && s[ix] == 'H') ix++;
        if (ix == n) break;
        if (ix == n - 1) {
            cout << -1 << '\n';
            return;
        }
        nx = max(nx, ix + 1);
        while (nx < n && s[nx] != s[nx - 1]) nx++;
        if (nx == n) {
            cout << -1 << '\n';
            return;
        }
        ans += nx - ix;
        ix++;
        s[nx] = char('H' + 'T' - s[nx]);
    }
    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}