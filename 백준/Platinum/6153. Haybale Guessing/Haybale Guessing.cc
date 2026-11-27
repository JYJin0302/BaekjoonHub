#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, q;
vector<int> num;

int find(int x, vector<int>& root) {
    if (x > n) return x;
    if (root[x] == 0 || root[x] == x) {
        return root[x] = x;
    }
    return root[x] = find(root[x], root);
}

void solve() {

    cin >> n >> q;

    vector<pair<pair<int, int>, int>> Q;
    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        Q.push_back(mp(mp(a, b), c));
        num.push_back(c);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    int sz = num.size();
    for (auto& [a, b] : Q) b = sz - 1 - (lower_bound(all(num), b) - num.begin());

    int l = 1, r = q - 1, ans = -1;

    while (l <= r) {
        int md = (l + r) >> 1;

        bool ok = 1;
        vector<int> L(sz, -1), R(sz, -1);
        vector<int> sL(sz, -1), sR(sz, -1);

        for (int i = 0; i <= md; i++) {
            int v = Q[i].y;
            auto [a, b] = Q[i].x;

            if (L[v] == -1) {
                L[v] = a, R[v] = b;
                sL[v] = a, sR[v] = b;
            }
            else {
                L[v] = max(L[v], a), R[v] = min(R[v], b);
                sL[v] = min(sL[v], a), sR[v] = max(sR[v], b);
            }
        }

        vector<int> nxt(n + 10);

        for (int i = 0; i < sz; i++) {
            if (L[i] == -1) continue;


            int pos = find(L[i], nxt);
            if (pos > R[i]) {
                ok = 0;
                break;
            }

            int ix = sL[i];
            while (ix <= sR[i]) {
                ix = find(ix, nxt);
                if (ix > sR[i]) break;
                nxt[ix]++;
                ix++;
            }
        }

        if (ok) {
            l = md + 1;
        }
        else {
            ans = md;
            r = md - 1;
        }
    }

    cout << ans + 1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}