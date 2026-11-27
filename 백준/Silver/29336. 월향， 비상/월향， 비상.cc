#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;
    vector<ll> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));
    reverse(all(A));

    int ix = 0;
    ll val = 0;
    while (m--) {
        ll a, b;
        cin >> a >> b;

        while (ix < n && val < b) {
            val += A[ix++] + a;
        }

        if (val < b) {
            cout << -1;
            return;
        }

        if (m == 0) {
            while (ix < n) val += A[ix++] + a;
            cout << val;
            return;
        }
    }



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}