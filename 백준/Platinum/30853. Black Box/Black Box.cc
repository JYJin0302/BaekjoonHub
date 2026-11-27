#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int seg[555050];
int n;

void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }

    int mid = (l + r) >> 1;
    update(l, mid, n * 2, u, v);
    update(mid + 1, r, n * 2 + 1, u, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int getIdx(int l, int r, int n, int k) {
    if (l == r) return l;

    int mid = (l + r) >> 1;
    if (seg[n * 2] < k) {
        k -= seg[n * 2];
        return getIdx(mid + 1, r, n * 2 + 1, k);
    }
    return getIdx(l, mid, n * 2, k);
}

void solve() {

    cin >> n;

    vector<int> A(n);
    for (auto& i : A) cin >> i;

    int ix = A[n - 1] % (n - 1);
    swap(A[0], A[ix]);

    int sz = 1;
    while (sz < n) sz *= 2;
    for (int i = 0; i < n; i++) {
        update(0, sz - 1, 1, i, 1);
    }

    vector<int> res(n);
    ix = 0;
    for (int i = 0; i < n; i++) {
        int idx = getIdx(0, sz - 1, 1, ix + 1);
        res[idx] = A[i];

        update(0, sz - 1, 1, idx, -1);
        int len = n - i - 1;
        if (len) ix = (ix + A[i] - 1) % len;
    }

    for (auto i : res) cout << i << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
