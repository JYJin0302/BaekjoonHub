#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, k, q;
    cin >> n >> k >> q;

    vector<ll> A(n);

    ll tot = 0;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = 0; j < k; j++) {

            ll x;
            cin >> x;
            x--;

            tmp += (x - i + n) % n;
        }
        A[i] = tmp;
        tot += tmp;
    }

    ll ans = tot / n;
    if (A[0] == 0 && tot != 0) ans++;

    if (ans <= q && tot%n == 0) cout << 1;
    else cout << 0;
}