#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    ll val = (1ll << A[0]) - 1;
    for (int i = 1; i < n; i++) {
        int dif = A[i] - A[i - 1];
        if (dif >= 2) {
            cout << -1 << '\n';
            return;
        }

        dif = 1 - dif;
        ll tv = (1ll << dif) - 1;

        if ((val & tv) == tv) {
            ll tt = (1ll << dif);
            if (val & tt) {
                val = (val - tv) << 1;
                val += tv;
            }
        }
        else {
            cout << -1 << '\n';
            return;
        }
        val++;
    }

    ll ans = val - n + 1;
    val = ans;
    for (int i = 0; i < n; i++) {
        if (__builtin_popcountll(val) != A[i]) {
            cout << -1 << '\n';
            return;
        }
        val++;
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