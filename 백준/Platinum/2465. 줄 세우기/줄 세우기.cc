#include <bits/stdc++.h>
using ll = long long;
using namespace std;

vector<int> pos, seg;

int get_idx(int n) {
    return lower_bound(pos.begin(), pos.end(), n) - pos.begin();
}

void update(int l, int r, int n, int u, int v, vector<int>& seg) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }

    int m = (l + r) / 2;
    update(l, m, n * 2, u, v, seg);
    update(m + 1, r, n * 2 + 1, u, v, seg);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> A(n), B(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
        pos.push_back(A[i]);
    }

    for (auto& i : B) cin >> i;

    // 좌표압축
    sort(pos.begin(), pos.end());
    pos.erase(unique(pos.begin(), pos.end()), pos.end());

    int sz = pos.size();
    int tn = 1;
    while (tn < sz) tn *= 2;

    seg = vector<int>(tn * 2);

    for (auto i : A) {
        update(0, tn - 1, 1, get_idx(i), 1, seg);
    }

    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        int l = 0, r = tn - 1, nn = 1;
        int tar = B[i] + 1;

        while (l < r) {

            int mid = (l + r) / 2;

            if (seg[nn * 2] >= tar) {
                r = mid;
                nn *= 2;
            }
            else {
                tar -= seg[nn * 2];
                l = mid + 1;
                nn = nn * 2 + 1;
            }
        }

        ans[i] = pos[l];
        update(0, tn - 1, 1, l, -1, seg);

    }

    for (auto i : ans) cout << i << '\n';
}