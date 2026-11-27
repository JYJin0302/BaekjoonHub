#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 1000000009

vector<ll> seg;  // max

void init(int l, int r, int n) {
    if (l == r) return;
    int mid = (l + r) / 2;
    init(l, mid, n * 2);
    init(mid + 1, r, n * 2 + 1);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

void update(int l, int r, int n, int u) {
    if (l > u || r < u)  return;
    if (l == u && r == u) return;
    int mid = (l + r) / 2;
    update(l, mid, n * 2, u);
    update(mid + 1, r, n * 2 + 1, u);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

ll smax(int l, int r, int n, int sl, int sr) {
    if (l > sr || r < sl) return -INF;
    if (l >= sl && r <= sr) return seg[n];
    int mid = (l + r) / 2;

    return max(smax(l, mid, n * 2, sl, sr), smax(mid + 1, r, n * 2 + 1, sl, sr));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    cin >> n >> d;

    int size = 1;
    while (size < n) size *= 2;
    seg = vector<ll>(size * 2);

    for (int i = 0; i < size; i++) {
        if (i < n) cin >> seg[size + i];
        else seg[size + i] = -INF;
    }

    init(size, size * 2 - 1, 1);

    for (int i = 1; i < n; i++) {
        seg[size + i] += max(0ll, smax(size, size * 2 - 1, 1, size + max(0, i - d), size + i - 1));
        update(size, size * 2 - 1, 1, size + i);
    }

    cout << seg[1];
}