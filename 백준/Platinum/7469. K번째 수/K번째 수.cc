#include <bits/stdc++.h>
using namespace std;

const int sz = 1 << 17;
vector<int> Mst[sz * 2];

void init(int n) {
    if (n >= sz) return;

    init(n * 2), init(n * 2 + 1);
    Mst[n].resize(Mst[n * 2].size() + Mst[n * 2 + 1].size());
    merge(Mst[n * 2].begin(), Mst[n * 2].end(), Mst[n * 2 + 1].begin(), Mst[n * 2 + 1].end(), Mst[n].begin());
}

int solve(int l, int r, int n, int sl, int sr, int k) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) {
        int ix = upper_bound(Mst[n].begin(), Mst[n].end(), k) - Mst[n].begin();
        return ix;
    }

    int m = (l + r) >> 1;
    return solve(l, m, n * 2, sl, sr, k) + solve(m + 1, r, n * 2 + 1, sl, sr, k);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, q;
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Mst[i+sz].push_back(x);
    }

    init(1);

    while (q--) {

        int a, b, k;
        cin >> a >> b >> k;

        int l = -1e9, r = 1e9, ans = -1;
        while (l <= r) {
            int md = (l + r) >> 1;

            int res = solve(0, sz-1, 1, a, b, md);
            if (res >= k) {
                ans = md;
                r = md - 1;
            }
            else l = md + 1;
        }
        cout << ans << '\n';
    }

}