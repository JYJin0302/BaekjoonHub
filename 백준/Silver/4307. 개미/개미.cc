#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {

        int l, n;
        cin >> l >> n;

        int ans1 = 0, ans2 = 0;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ans1 = max(ans1, min(x, l - x));
            ans2 = max(ans2, max(x, l - x));
        }

        cout << ans1 << ' ' << ans2 << '\n';
    }

}