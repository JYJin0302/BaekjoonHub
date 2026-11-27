#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

void solve() {

    int m;
    cin >> m;

    vector<int> clk(m);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;

        int h = s[0] * 10 + s[1];
        int min = s[3] * 10 + s[4];
        clk[i] = h*60 + min;
    }

    int ans = m;

    for (int t = 0; t < 12*60; t++) {

        // test with this range
        map<int, int> cnt;
        int res = 0;

        for (int i = 0; i < m; i++) {

            int tt = t * i % (12 * 60);

            int nt = (clk[i] - tt + 720) % 720;
            if (cnt[nt] == 0) res++;
            cnt[nt]++;
        }
        ans = min(ans, res);
    }

    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
