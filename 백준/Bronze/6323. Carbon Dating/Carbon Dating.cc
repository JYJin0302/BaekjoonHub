#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int a, b;
    cin >> a >> b;

    int tc = 0;
    while (a + b) {

        ld v = 1.0 * b / a;

        v /= 810;
        ld tans = logl(v) / logl(0.5);
        tans *= 5730;

        tans = abs(tans);

        ll ans = 0;
        if (tans >= 10000) {
            ans = round(tans / 1000);
            ans *= 1000;
        }
        else {
            ans = round(tans / 100);
            ans *= 100;
        }

        cout << "Sample #" << ++tc << '\n';
        cout << "The approximate age is " << ans << " years.\n\n";
        cin >> a >> b;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}