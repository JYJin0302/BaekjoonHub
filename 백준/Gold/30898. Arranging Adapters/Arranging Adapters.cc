#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    ll n, s;
    cin >> n >> s;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));
    if (s == 1 || n == 1) {
        cout << 1 << '\n';
        return;
    }

    s -= 2;
    A.pop_back();
    A.pop_back();

    int l = 0, r = n-2;
    int ans = 2;
    while (l <= r) {
        int md = (l + r) >> 1;

        int c1 = 0, c2 = 0;
        ll tot = 0;
        for (int i = 0; i < md; i++) {
            auto f = A[i];
            if (f % 3 == 0) tot += f / 3;
            else if (f % 3 == 1) c1 ++, tot += f / 3 + 1;
            else c2++, tot += f / 3 + 1;
        }

        tot -= min(c1, c2);
        c1 -= min(c1, c2);
        tot -= c1 / 2;

        if (tot <= s) {
            ans = 2 + md;
            l = md + 1;
        }
        else r = md - 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}