#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
using ld = long double;

int n, m;
vector<int> A;
int getIdx(int x) {
    return lower_bound(A.begin(), A.end(), x) - A.begin();
}

int seg[202020];

void update(int ix, int val) {
    for (ix += n+1; ix; ix >>= 1) {
        seg[ix] = min(seg[ix], val);
    }
}

int getMin(int l, int r) {
    int res = 0x3f3f3f3f;
    for (l += n+1, r += n+1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0); 


    cin >> m >> n;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        A.push_back(x);
    }

    vector<int> C(n);
    for (auto& i : C) cin >> i;

    memset(seg, 0x3f3f3f3f, sizeof(seg));

    vector<int> L(n, -1), R(n, -1), L2(n, -1);
    L[0] = 0;
    L2[0] = -1;
    for (int i = 1; i < n; i++) {
        if (C[i] == C[i - 1]) {
            L[i] = L[i - 1];
            L2[i] = L2[i - 1];
        }
        else {
            L[i] = i;
            L2[i] = L[i - 1];
        }
    }

    vector<int> ans(n);
    int tx = 0;
    while (tx < n && C[tx] == C[0]) {
        ans[tx] = 1;
        update(tx, 1);
        tx++;
    }

    for (int i = tx; i < n; i++) {

        int v = A[i];

        int lx = L[i];

        int rbound = 2* A[lx] - v;
        int lbound = 0;
        if (lx) {
            lbound = 2 * A[lx - 1] - v;
        }

        lbound = getIdx(lbound);
        lbound = max(lbound, L2[i]);
        rbound = getIdx(rbound + 1) - 1;

        int res = 0x3f3f3f3f;
        if (rbound >= lbound) {
            res = min(res, getMin(lbound, rbound + 1));
        }
        res = min(res, getMin(lx, i));

        update(i, res+1);
        ans[i] = res+1;
    }

    int t = 0x3f3f3f3f;
    int ix = n - 1;
    while (ix >= 0 && C[ix] == C[n - 1]) {
        t = min(t, ans[ix]);
        ix--;
    }
    cout << t;
}