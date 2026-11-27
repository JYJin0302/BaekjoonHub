#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int C, N, O;
vector<int> maxSeg, minSeg;
vector<int> lazy;

void init(int l, int r, int n) {
    if (l == r) {
        if (l >= C) {
            maxSeg[n] = -1;
            minSeg[n] = N+10;
        }
        return;
    }

    int m = (l + r) / 2;
    init(l, m, n * 2);
    init(m + 1, r, n * 2 + 1);
    maxSeg[n] = max(maxSeg[n * 2], maxSeg[n * 2 + 1]);
    minSeg[n] = min(minSeg[n * 2], minSeg[n * 2 + 1]);
}

void goLazy(int l, int r, int n) {
    if (lazy[n] != 0) {
        maxSeg[n] += lazy[n];
        minSeg[n] += lazy[n];
        if (l != r) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void update(int l, int r, int n, int sl, int sr, ll v) {
    goLazy(l, r, n);

    if (l > sr || r < sl) return;
    if (l >= sl && r <= sr) {
        lazy[n] = v;
        goLazy(l, r, n);
        return;
    }

    int m = (l + r) / 2;
    update(l, m, n * 2, sl, sr, v);
    update(m + 1, r, n * 2 + 1, sl, sr, v);
    minSeg[n] = min(minSeg[n * 2], minSeg[n * 2 + 1]);
    maxSeg[n] = max(maxSeg[n * 2], maxSeg[n * 2 + 1]);
}

ll getMax(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return -1;
    if (l >= sl && r <= sr) return maxSeg[n];

    int m = (l + r) / 2;
    return max(getMax(l, m, n * 2, sl, sr), getMax(m + 1, r, n * 2 + 1, sl, sr));
}

ll getMin(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl) return N+10;
    if (l >= sl && r <= sr) return minSeg[n];

    int m = (l + r) / 2;
    return min(getMin(l, m, n * 2, sl, sr), getMin(m + 1, r, n * 2 + 1, sl, sr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> C >> N >> O;

    int sn = 1;
    while (sn < C) sn *= 2;

    minSeg = vector<int>(sn * 2);
    maxSeg = vector<int>(sn * 2);
    lazy = vector<int>(sn * 2);

    init(0, sn - 1, 1);

    while (O--) {

        string s;
        cin >> s;

        int x = s.length();
        int a, b, c;

        if (x == 5) {
            // state
            cin >> a;
            cout << getMax(0, sn - 1, 1, a, a) << '\n';
        }
        else if (x == 6) {
            // change
            cin >> a >> b;
            int v = getMax(0, sn - 1, 1, a, a);

            if (b < 0) b = -min(abs(b), v);
            else b = min(b, N - v);

            cout << b << '\n';
            update(0, sn - 1, 1, a, a, b);
        }
        else {
            // group change
            cin >> a >> b >> c;

            int mv = getMin(0, sn - 1, 1, a, b);
            int Mv = getMax(0, sn - 1, 1, a, b);

            if (c < 0) c = -min(-c, mv);
            else c = min(c, N - Mv);

            cout << c << '\n';
            update(0, sn - 1, 1, a, b, c);
        }

    }

}