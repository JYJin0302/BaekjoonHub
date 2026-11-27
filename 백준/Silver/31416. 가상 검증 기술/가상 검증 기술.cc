#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()



void solve() {
    int ta, tb, va, vb;
    cin >> ta >> tb >> va >> vb;

    int ans = 1e9;
    for (int i = 0; i <= va; i++) {

        int val = max(i * ta, (va - i) * ta + vb * tb);
        ans = min(ans, val);
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