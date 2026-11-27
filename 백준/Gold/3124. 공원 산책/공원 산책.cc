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
    string s1, s2;
    cin >> s1 >> s2;

    ll ans = 0;
    if (s1 == string(n, '1')) {
        ans++;
        ll cnt = 0;
        for (auto f : s2) cnt += (f - '0');

        ans += cnt * (cnt - 1);
        cout << ans << '\n';
        return;
    }

    if (s1 == string(n, '0')) {
        cout << 0;
        return;
    }


    vector<bool> vis(n);

    int ix = 0;

    while (1) {
        if (s1[ix] == '0') {
            vis[ix] = 1;
            ix++;
            continue;
        }
        if (vis[ix]) break;

        ll cnt = 0;
        int l = (ix + n - 1) % n;
        int r = (ix + 1) % n;

        while (s1[l] == '1') {
            l = (l + n - 1) % n;
        }
        while (s1[r] == '1') {
            r = (r + 1) % n;
        }

        if (l == r) {
            for (auto f : s2) cnt += f - '0';
            cout << cnt * (cnt - 1) / 2 << '\n';
            return;
        }

        int tx = l;
        while (tx != r) {
            vis[tx] = 1;
            cnt += s2[tx] - '0';
            tx = (tx + 1) % n;
        }


        ans += cnt * (cnt - 1) / 2;
        ix = r;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}