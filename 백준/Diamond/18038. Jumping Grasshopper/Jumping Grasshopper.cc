#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int A[300001];
vector<int> seg; // return idx

void init(int l, int r, int n) {
    if (l == r) {
        seg[n] = l;
        return;
    }
    int m = (l + r) >> 1;
    init(l, m, n * 2);
    init(m + 1, r, n * 2 + 1);
    if (A[seg[n * 2]] > A[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
    else seg[n] = seg[n * 2 + 1];
}

void update(int l, int r, int n, int u) {
    if (l > u || r < u) return;
    if (l == u && r == u) return;

    int m = (l + r) >> 1;
    update(l, m, n * 2, u);
    update(m + 1, r, n * 2 + 1, u);
    if (A[seg[n * 2]] > A[seg[n * 2 + 1]]) seg[n] = seg[n * 2];
    else seg[n] = seg[n * 2 + 1];
}

int getMax(int l, int r, int n, int sl, int sr) {

    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    int ix1 = getMax(l, m, n * 2, sl, sr);
    int ix2 = getMax(m + 1, r, n * 2 + 1, sl, sr);

    if (A[ix1] > A[ix2]) return ix1;
    return ix2;
}

int getIdx(int l, int r, int n, int sl, int sr, int val, int t) {
    if (l > sr || r < sl) return -1;
    if (A[seg[n]] <= val) return -1;
    if (l == r) return seg[n];

    int m = (l + r) >> 1;

    if (t == 0) {
        int res = getIdx(l, m, n * 2, sl, sr, val, t);
        if (res != -1) return res;
        return getIdx(m + 1, r, n * 2 + 1, sl, sr, val, t);
    }

    int res = getIdx(m + 1, r, n * 2 + 1, sl, sr, val, t);
    if (res != -1) return res;
    return getIdx(l, m, n * 2, sl, sr, val, t);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    memset(A, -1, sizeof(A));

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> A[i];

    int sn = 1;
    while (sn < n + 1) sn *= 2;

    seg = vector<int>(sn * 2);
    init(0, sn - 1, 1);

    while (m--) {

        char c;
        int ix;
        cin >> c >> ix;

        if (c == 'L') {

            int lMax = getMax(0, sn - 1, 1, 0, ix - 1);
            int rMax = getMax(0, sn - 1, 1, ix + 1, n);
            int currVal = A[ix];
            // cout << ix << ' ' << lMax << ' ' << rMax << '\n';

            if (A[lMax] < currVal) cout << ix << '\n';
            else if (A[rMax] < currVal) {
                int ans = getIdx(0, sn - 1, 1, 0, ix - 1, currVal, 1);
                cout << ans << '\n';
            }
            else if (A[lMax] < A[rMax]) {
                int ans = getIdx(0, sn - 1, 1, ix + 1, n, A[lMax], 0);
                cout << ans << '\n';
            }
            else {
                int ans = getIdx(0, sn - 1, 1, 0, ix - 1, A[rMax], 1);
                cout << ans << '\n';
            }
        }
        else if (c == 'R') {
            int lMax = getMax(0, sn - 1, 1, 0, ix - 1);
            int rMax = getMax(0, sn - 1, 1, ix + 1, n);
            int currVal = A[ix];

            // cout << ix << ' ' << lMax << ' ' << rMax << '\n';

            if (A[rMax] < currVal) cout << ix << '\n';
            else if (A[lMax] < currVal) {
                int ans = getIdx(0, sn - 1, 1, ix + 1, n, currVal, 0);
                cout << ans << '\n';
            }
            else if (A[lMax] < A[rMax]) {
                int ans = getIdx(0, sn - 1, 1, ix + 1, n, A[lMax], 0);
                cout << ans << '\n';
            }
            else {
                int ans = getIdx(0, sn - 1, 1, 0, ix - 1, A[rMax], 1);
                cout << ans << '\n';
            }
        }
        else {
            // update
            int val;
            cin >> val;

            A[ix] = val;
            update(0, sn - 1, 1, ix);
        }
    }
}