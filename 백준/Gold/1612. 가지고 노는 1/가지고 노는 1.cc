#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    cin >> n;

    int ans = 0;
    ll val = 0;

    for (int i = 0; i < n + 20; i++) {
        val = val * 10 + 1;
        val %= n;
        ans++;
        if (val == 0) {
            cout << ans;
            return;
        }
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}