#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, m;
    cin >> n >> m;

    int ans1 = 0, ans2 = -1;
    for (int j = 1; j <= 100; j++) {
        if (j * j >= n && j * j <= m) {
            if (ans2 == -1) ans2 = j * j;
            ans1 += j * j;
        }
    }
    if (ans1 == 0) cout << -1 << '\n';
    else cout << ans1 << '\n' << ans2 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}