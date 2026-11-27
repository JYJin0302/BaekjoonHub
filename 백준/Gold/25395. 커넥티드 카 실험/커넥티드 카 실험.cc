#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, s;
    cin >> n >> s;
    s--;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first;
    for (auto& i : A) cin >> i.second;

    int lx = s, lh = A[s].second;
    int rx = s, rh = A[s].second;

    while (1) {
        bool update = 0;

        while (lx > 0) {
            if (A[lx].first - A[lx - 1].first <= lh) {
                update = 1;
                lh = max(lh - (A[lx].first - A[lx - 1].first), A[lx - 1].second);
                lx--;
                if (rx < n - 1) {
                    rh = max(rh, lh - (A[rx].first - A[lx].first));
                }
            }
            else break;
        }

        while (rx < n - 1) {
            if (A[rx+1].first - A[rx].first <= rh) {
                update = 1;
                rh = max(rh - (A[rx+1].first - A[rx].first), A[rx+1].second);
                rx++;
                if (lx > 0) {
                    lh = max(lh, rh - (A[rx].first - A[lx].first));
                }
            }
            else break;
        }

        if (!update) break;
    }

    for (int i = lx; i <= rx; i++) {
        cout << i + 1 << ' ';
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}