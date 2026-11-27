#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve() {

    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    string ans(n, '.');
    int gi = 0, hi = 0, cnt = 0;
    while (1) {

        while (gi < n && s[gi] == 'H') gi++;
        while (hi < n && s[hi] == 'G') hi++;

        int ix = min(gi, hi);

        if (ix >= n) break;
        cnt++;
        if (ix == gi) {
            int tmp = min(n - 1, gi + k);
            if (ans[tmp] == '.') ans[tmp] = 'G';
            else ans[tmp - 1] = 'G';
            gi += 2 * k + 1;
        }
        else {
            int tmp = min(n - 1, hi + k);
            if (ans[tmp] == '.') ans[tmp] = 'H';
            else ans[tmp - 1] = 'H';
            hi += 2 * k + 1;
        }
    }
    cout << cnt << '\n' << ans << '\n';;


}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}