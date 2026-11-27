#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 500001;

vector<int> num;
int getIdx(int n) {
    return lower_bound(num.begin(), num.end(), n) - num.begin();
}

int segU2[MAX_N * 4];
int segU3[MAX_N * 4];
int segD2[MAX_N * 4];
int segD3[MAX_N * 4];

void update(int l, int r, int n, int u, int v, int seg[]) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] = max(seg[n], v);
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v, seg);
    update(m + 1, r, n * 2 + 1, u, v, seg);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int getMax(int l, int r, int n, int sl, int sr, int seg[]) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) return seg[n];

    int m = (l + r) >> 1;
    return max(getMax(l, m, n * 2, sl, sr, seg), getMax(m + 1, r, n * 2 + 1, sl, sr, seg));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) {
        cin >> i;
    }

    num = A;
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    for (auto& i : A) i = getIdx(i);

    int sn = 1, m = num.size();
    while (sn < m) sn *= 2;

    for (int i = 0; i < n; i++) {

        int tval;

        tval = getMax(0, sn - 1, 1, 0, A[i] - 1, segU2);
        if (tval <= 1) update(0, sn - 1, 1, A[i], tval + 1, segU2);
        else update(0, sn - 1, 1, A[i], tval + 1, segU3);

        tval = getMax(0, sn - 1, 1, A[i] + 1, sn - 1, segD2);
        if (tval <= 1) update(0, sn - 1, 1, A[i], tval + 1, segD2);
        else update(0, sn - 1, 1, A[i], tval + 1, segD3);

        tval = getMax(0, sn - 1, 1, 0, A[i] - 1, segU3);
        if (tval) update(0, sn - 1, 1, A[i], tval + 1, segU3);
        tval = getMax(0, sn - 1, 1, A[i] + 1, sn - 1, segD3);
        if (tval) update(0, sn - 1, 1, A[i], tval + 1, segD3);

        tval = getMax(0, sn - 1, 1, A[i] + 1, sn - 1, segU3);
        if (tval) update(0, sn - 1, 1, A[i], tval + 1, segD2);
        tval = getMax(0, sn - 1, 1, 0, A[i] - 1, segD3);
        if (tval) update(0, sn - 1, 1, A[i], tval + 1, segU2);

        update(0, sn - 1, 1, A[i], 1, segU2);
        update(0, sn - 1, 1, A[i], 1, segD2);
    }

    cout << max(segD3[1], segU3[1]);

}
