#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;

        int val = lower_bound(all(A), x + 1) - A.begin();

        ll l = 0, r = 10000, res = 0;
        while (l <= r) {
            ll md = (l + r) >> 1;
            if (md * (md - 1) * 3 + 1 <= val) {
                res = md;
                l = md + 1;
            }
            else r = md - 1;
        }
        cout << res << ' ';
    }

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}