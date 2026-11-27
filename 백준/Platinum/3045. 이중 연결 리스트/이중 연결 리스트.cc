#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int L[505050], R[505050];

void solve() {

    int n, m;
    cin >> n >> m;

    for (int i = 0; i <= n + 1; i++) {
        L[i] = i - 1;
        R[i] = i + 1;
    }

    while (m--) {
        char c;
        int a, b;
        cin >> c >> a >> b;

        if (c == 'A') {
            if (R[a] == b) continue;

            int tl = L[a], tr = R[a];
            R[tl] = tr;
            L[tr] = tl;

            int tx = L[b];
            R[tx] = a;
            L[a] = tx;
            R[a] = b;
            L[b] = a;
        }
        else {
            if (R[b] == a) continue;

            int tl = L[a], tr = R[a];
            R[tl] = tr;
            L[tr] = tl;

            int tx = R[b];
            L[tx] = a;
            R[a] = tx;
            L[a] = b;
            R[b] = a;
        }
    }

    vector<int> res;
    int cur = 0;
    for (int i = 0; i < n + 2; i++) {
        res.push_back(cur);
        cur = R[cur];
    }

    vector<int> tmp;
    vector<int> from(n + 10);
    for (auto f : res) {
        if (f == 0) {
            tmp.push_back(0);
            continue;
        }
        int ix = lower_bound(all(tmp), f) - tmp.begin();
        if (ix == tmp.size()) {
            from[f] = tmp.back();
            tmp.push_back(f);
        }
        else {
            tmp[ix] = f;
            from[f] = tmp[ix - 1];
        }
    }

    vector<bool> chk(n + 10);
    cur = n + 1;
    while (cur) {
        chk[cur] = 1;
        cur = from[cur];
    }


    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (chk[i]) continue;
        ans.push_back(i);
    }

    cout << ans.size() << '\n';

    int ix = 0;
    if (!ans.empty() && ans[0] == 1) {
        while (ix < ans.size() && ans[ix] == ix + 1) ix++;

        for (int f = ix; f >= 1; f--) {
            cout << "A " << f << ' ' << f + 1 << '\n';
        }
    }

    while (ix < ans.size()) {
        int v = ans[ix++];
        cout << "B " << v << ' ' << v - 1 << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}