#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ix = 0;
    while (ix < n && s[ix] == '.') ix++;

    vector<int> d;
    while (ix < n) {

        int nx = ix + 1;
        while (nx < n && s[nx] == '.') nx++;

        if (nx == n) break;
        d.push_back(nx - ix - 1);
        ix = nx;
    }

    sort(all(d));

    int cnt = 0;
    for (auto f : s) if (f == 'X') cnt++;

    int ans = n + cnt;
    for (int i = 0; i < d.size(); i++) {
        if (m >= d[i]) {
            m -= d[i];
            ans -= 2;
        }
        else break;
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