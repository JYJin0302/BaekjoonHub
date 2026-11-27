#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> pos, segL, segR;

int get_idx(int n) {
    return lower_bound(pos.begin(), pos.end(), n) - pos.begin();
}

void update(int l, int r, int n, int u, int v, vector<int>& seg) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = v;
        return;
    }

    int m = (l + r) / 2;
    update(l, m, n * 2, u, v, seg);
    update(m + 1, r, n * 2 + 1, u, v, seg);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int smax(int l, int r, int n, int sl, int sr, vector<int>& seg) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) / 2;
    return max(smax(l, m, n * 2, sl, sr, seg), smax(m + 1, r, n * 2 + 1, sl, sr, seg));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<tuple<int, int, int>> inp(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        pos.push_back(a + b);
        pos.push_back(b - a);
        inp[i] = { b, a, i };
    }

    // 좌표압축
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());


    sort(inp.begin(), inp.end());

    int sz = pos.size();
    int tn = 1;
    while (tn < sz) tn *= 2;

    vector<int> ans(n);

    segL = vector<int>(tn * 2);
    segR = vector<int>(tn * 2);
    for (const auto i : inp) {
        int a, b, j;
        tie(b, a, j) = i;

        int res = 0;
        res = smax(0, tn - 1, 1, get_idx(a + b), tn - 1, segL);
        res = max(res, smax(0, tn - 1, 1, get_idx(b - a), tn - 1, segR));

        ans[j] = res + 1;

        update(0, tn - 1, 1, get_idx(a + b), res + 1, segL);
        update(0, tn - 1, 1, get_idx(b - a), res + 1, segR);
    }

    while (q--) {
        int x;
        cin >> x;

        cout << ans[x - 1] << '\n';
    }

}