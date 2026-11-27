#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int b, n;
    cin >> b >> n;
    vector<int> A(b);
    for (auto& i : A) cin >> i;

    ll l = 0, r = 1e17, res = -1;
    while (l <= r) {
        ll md = (l + r) >> 1;

        ll cnt = 0;
        for (auto f : A) {
            cnt += (md + f-1) / f;
        }

        if (cnt >= n) {
            res = md;
            r = md - 1;
        }
        else l = md + 1;
    }

    res--;
    ll c = 0;
    for (auto f : A) c += (res + f - 1) / f;
    ll nd = n - c;

    for (int i = 0; i < b; i++) {
        if (res % A[i] == 0) {
            nd--;
            if (nd == 0) {
                cout << i + 1 << '\n';
                return;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        cout << "Case #" << i << ": ";
        solve();
    }
}