#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n; cin >> n;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int val = 0;
        if (a == b && a == c) val = 10000 + a * 1000;
        else if (a == b || a == c) val = 1000 + a * 100;
        else if (b == c) val = 1000 + b * 100;
        else val = max({ a, b, c }) * 100;

        ans = max(ans, val);
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