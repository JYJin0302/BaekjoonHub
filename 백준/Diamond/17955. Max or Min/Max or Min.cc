#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> pos[200010];
int cnt[200010], A[200010], len[200010];


vector<int> seg;
int res = 0;

void init(int l, int r, int n) {
    if (l == r) return;
    int m = (l + r) >> 1;
    init(l, m, n * 2);
    init(m + 1, r, n * 2 + 1);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void update(int l, int r, int n, int u, int v) {

    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = v;
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v);
    update(m + 1, r, n * 2 + 1, u, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int getMax(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return -1;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return max(getMax(l, m, n * 2, sl, sr), getMax(m + 1, r, n * 2 + 1, sl, sr));
}

int n, m, sn;
void upd(int ix) {

    if (A[ix] == 1) {

        int pi = getMax(0, sn - 1, 1, 0, ix);

        if (pi == ix) {
            if (A[ix+1] != 0) update(0, sn - 1, 1, ix + 1, ix + 1);
            if (len[ix] % 2 == 0) res--;
            if (A[ix+1] == -1) len[ix + 1] = len[ix] - 1;
            len[ix] = 0;
        }
        else {
            int tmp = len[pi];
            res -= tmp / 2;
            len[pi] = ix - pi;
            res += len[pi] / 2;
            //update(0, sn - 1, 1, ix, 0);
            if (pi + tmp - 1 > ix) {
                update(0, sn - 1, 1, ix + 1, ix + 1);
                len[ix + 1] = tmp - len[pi] - 1;
                res += len[ix + 1] / 2;
            }
        }
        update(0, sn - 1, 1, ix, -1);
        A[ix] = 0;
    }
    else {
        int newLen = 1, newPos = ix;
        if (ix + 1 < n && A[ix+1] == 1) {
            newLen += len[ix + 1];
            res -= len[ix + 1] / 2;
            len[ix + 1] = 0;
            update(0, sn - 1, 1, ix + 1, -1);
        }
        if (ix - 1 >= 0 && A[ix - 1] == 1) {
            int tx = getMax(0, sn - 1, 1, 0, ix - 1);
            newLen += ix - tx;
            res -= (ix - tx) / 2;
            newPos = tx;
        }
        update(0, sn - 1, 1, ix, -1);
        len[ix] = 0;
        res += newLen / 2;
        len[newPos] = newLen;
        update(0, sn - 1, 1, newPos, newPos);
        A[ix] = -1;
    }
    /*
    cout << "Curr update: " << ix << ' ' << A[ix] << ", res: " << res << '\n';
    for (int i = 0; i < n; i++) cout << getMax(0, sn - 1, 1, i, i) << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << A[i] << ' ';
    cout << '\n';
    for (int i = 0; i < n; i++) cout << len[i] << ' ';
    cout << '\n';
    */
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> n>> m;

    sn = 1;
    while (sn < n) sn *= 2;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pos[x].push_back(i);
        cnt[x]++;
    }

    seg = vector<int>(sn * 2);
    for (int i = 0; i < n; i++) {
        seg[i + sn] = i;
    }
    init(0, sn - 1, 1);

    for (int i = 0; i < n; i++) {
        A[i] = 1;
        len[i] = 1;
    }

    vector<int> ans(m + 1);
    for (int i = 1; i <= m; i++) {
        for (auto j : pos[i]) upd(j);
        int tres = res;
        if (A[n - 1] * A[0] == -1) {
            int ti = seg[1];
            tres -= len[ti] / 2 + len[0] / 2;
            tres += (len[ti] + len[0]) / 2;
        }
        ans[i] = tres;
        for (auto j : pos[i]) upd(j);
    }

    //for (int i = 1; i <= m; i++) cout << ans[i] << ' ';
   // cout << '\n';
    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) cout << -1 << ' ';
        else cout << n - cnt[i] + ans[i] << ' ';
    }
}
