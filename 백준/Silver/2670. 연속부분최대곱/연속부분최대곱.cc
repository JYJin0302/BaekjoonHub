#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<ld> A(n);
    for (auto& i : A) cin >> i;

    ld ans = A[0], val = A[0];
    for (int i = 1; i < n; i++) {
        val = max((ld)1.0, val) * A[i];
        ans = max(ans, val);
    }

    cout << fixed << setprecision(3);
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}