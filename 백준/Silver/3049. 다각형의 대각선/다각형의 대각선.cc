#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 2; j <= n; j++) {
            int l = j - i - 1;
            int r = i - 1 + n - j;
            ans += l * r;
        }
    }
    cout << ans/2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}