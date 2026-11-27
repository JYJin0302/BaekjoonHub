#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i = 0; i < min(n, a + b); i++) {
        ans += 1 << (n - 1 - i);
    }

    for (int i = n; i < a + b; i++) {
        ans -= 1 << (i - n);
    }
    cout << ans << '\n';
}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}