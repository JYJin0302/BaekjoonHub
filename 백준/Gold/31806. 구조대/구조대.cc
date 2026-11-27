#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, pair<int, int>>> A;
    for (int i = 0; i < n; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        A.push_back(mp(x, mp(l, r)));
    }
    sort(all(A));

    vector<pair<int, int>> res;

    int ix = 0, cnt = 0;
    while (ix < n) {
        cnt++;
        int nx = ix;
        while (nx < n && A[nx].x == A[ix].x) nx++;
        vector<pair<int, int>> tmp;
        for (int i = ix + 1; i < nx; i++) {
            auto [cl, cr] = A[i].y;
            auto [pl, pr] = A[i - 1].y;

            int tl = cl - m;
            if (tl < pr) {
                tmp.push_back(mp(tl, pr));
            }
        }

        if (!tmp.empty()) {
            auto [a, b] = tmp[0];
            for (int i = 1; i < tmp.size(); i++) {
                auto [na, nb] = tmp[i];
                if (na <= b) b = max(b, nb);
                else {
                    res.push_back(mp(a, 1));
                    res.push_back(mp(b, -1));
                    a = na, b = nb;
                }
            }
            res.push_back(mp(a, 1));
            res.push_back(mp(b, -1));

        }
        
        ix = nx;
    }

    int ans = 0, val = 0;
    sort(all(res));
    for (auto [a, b] : res) {
        val += b;
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