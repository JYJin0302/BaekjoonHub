#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    if (s == string(n, '1')) {
        cout << 1;
        return;
    }
    if (s == string(n, '0')) {
        cout << 0;
        return;
    }

    vector<int> ans(n);
    int mD = n-1;
    int ix = 0;
    while (ix < n) {
        while (ix < n && s[ix] == '0') ix++;

        if (ix == n) break;
        int nx = ix;
        while (nx < n && s[nx] == '1') nx++;

        int len = nx - ix;

        if (ix == 0 || nx == n) {
            mD = min(mD, len - 1);
            for (int i = 0; i < len; i++) {
                ans[i] += (len + 2*i) / (2*i + 1);
            }
        }
        else {
            for (int i = 0; i < len; i++) {
                int val = (len + 2 * i) / (2 * i + 1);
                if (len < 2 * i + 1) {
                    mD = min(mD, i - 1);
                    break;
                }
                ans[i] += val;
            }
        }

        ix = nx;

    }

    cout << ans[mD];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}