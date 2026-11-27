#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int x;
            cin >> x;
            A.push_back(mp(x, i));
        }
    }
    sort(all(A));

    int l = 0, r = 0;
    vector<int> cnt(n);
    int cc = 0;
    int ans = 1e9;
    while (r < n*m) {
        while (r < n*m && cc < n) {
            cnt[A[r].second]++;
            if (cnt[A[r].second] == 1) cc++;
            r++;
        }
        if (cc != n) break;

        while (l < r && cc == n) {
            cnt[A[l].second]--;
            if (cnt[A[l].second] == 0) cc--;
            l++;
        }
        ans = min(ans, A[r-1].first - A[l - 1].first);
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