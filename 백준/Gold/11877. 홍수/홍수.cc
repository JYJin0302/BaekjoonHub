#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    ll n, x;
    cin >> n >> x;

    ll lim = (n - 2) * (n - 1) / 2;

    if (x > lim) {
        cout << -1;
        return 0;
    }

    vector<bool> used(n + 1);
    used[n] = 1;

    ll cnt = 0, c = 1;
    while (cnt != x) {

        if (cnt + n - 1 - c <= x) {
            cnt += n - 1 - c;
            used[c] = 1;
        }

        c++;
    }

    cout << n << ' ';
    for (int i = 1; i < n; i++) {
        if (used[i]) cout << i << ' ';
    }

    for (int i = n - 1; i >= 1; i--) {
        if (!used[i]) cout << i << ' ';
    }


}