#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> seg, lazy;

void goLazy(int l, int r, int n){
    if (lazy[n] != 0) {
        seg[n] += lazy[n];
        if (l != r) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}


void update(int l, int r, int n, int sl, int sr, int v) {
    goLazy(l, r, n);
    if (l > sr || r < sl)return;
    if (l >= sl && r <= sr) {
        lazy[n] += v;
        goLazy(l, r, n);
        return;
    }
    int m = (l + r) >> 1;

    update(l, m, n * 2, sl, sr, v);
    update(m + 1, r, n * 2 + 1, sl, sr, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int getMax(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return max(getMax(l, m, n * 2, sl, sr), getMax(m + 1, r, n * 2 + 1, sl, sr));
}

void solve() {

    int n;
    cin >> n;

    vector<int> pos;
    vector<tuple<int, int, int>> line;
    // y, xl, xr

    for (int i = 0; i < n; i++) {

        int k;
        cin >> k;
        vector<pair<int, int>> A(k);
        for (auto& j : A) cin >> j.first >> j.second;

        for (int j = 0; j < k; j++) {
            int pv = (j + k - 1) % k;
            if (A[pv].second == A[j].second) {
                line.push_back({ A[j].second, A[pv].first, A[j].first });
                pos.push_back(A[pv].first);
                pos.push_back(A[j].first);
            }
        }
    }

    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    for (int i = 0; i < line.size(); i++) {
        int a, b, c;
        tie(a, b, c) = line[i];
        b = lower_bound(pos.begin(), pos.end(), b) - pos.begin();
        c = lower_bound(pos.begin(), pos.end(), c) - pos.begin();
        line[i] = { a, b, c };
    }

    sort(line.begin(), line.end());

    int m = pos.size();
    int sn = 1;
    while (sn < m) sn *= 2;

    seg = vector<int>(sn * 2);
    lazy = vector<int>(sn * 2);

    int ans = 0;
    for(auto i : line){
        int a, b, c;
        tie(a, b, c) = i;

        if (b > c) {
            update(0, sn - 1, 1, c+1, b, -1);
        }
        else update(0, sn - 1, 1, b+1, c, 1);
        ans = max(ans, seg[1]);
    }
    cout << ans << '\n';

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}