#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll A[202020];
ll sA[202020];

ll getVal(int l, int r, int pos) {
    ll res = 0;
    int lft = pos - l;
    res += 1ll * lft * A[pos] - (sA[pos - 1] - sA[l - 1]);
    int rgt = r - pos;
    res += sA[r] - sA[pos] - rgt * A[pos];
    return res;
}
void solve() {

    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) sA[i] = sA[i - 1] + A[i];

    while (q--) {
        ll l, r;
        cin >> l >> r;

        int a = lower_bound(A, A + n + 1, l) - A;
        int b = lower_bound(A, A + n + 1, r + 1) - A - 1;

        int len = b - a + 1;
        if (len <= 1) {
            cout << 0 << '\n';
            continue;
        }

        ll mx = max(getVal(a, b, a), getVal(a, b, b));
        ll mn = getVal(a, b, a + len / 2);
        cout << mx - mn << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}