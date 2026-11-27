#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int L, n, m;
    cin >> L >> n >> m;
    vector<int> A(n);
    for (auto& i : A) cin >> i;
    sort(all(A));

    int l = 1, r = L, res = -1;
    while (l <= r) {
        int md = (l + r) >> 1;

        int pv = 0;
        int nd = 0;
        for (auto f : A) {
            if (f >= pv + md) {
                pv = f;
            }
            else nd++;
        }

        if (L - pv < md) {
            nd++;
        }

        if (nd <= m) {
            res = md;
            l = md + 1;
        }
        else r = md - 1;
    }
    cout << res << '\n';

}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) {
        solve();
    }
}