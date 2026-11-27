#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


int n, q;
int segM[101010], segm[101010];
void update(int ix, int val, int seg[], bool getMax = 0) {
    for (seg[ix += n] = val; ix > 1; ix >>= 1) {
        if (getMax) seg[ix >> 1] = max(seg[ix], seg[ix ^ 1]);
        else seg[ix >> 1] = min(seg[ix], seg[ix ^ 1]);
    }
}

int getVal(int l, int r, int seg[], bool getMax = 0) {
    int res = 0;
    if (getMax) {}
    else res = 0x3f3f3f3f;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) {
            if (getMax) res = max(res, seg[l++]);
            else res = min(res, seg[l++]);
        }
        if (r & 1) {
            if (getMax) res = max(res, seg[--r]);
            else res = min(res, seg[--r]);
        }
    }
    return res;
}

void solve() {
    cin >> n >> q;
    
    memset(segm, 0x3f3f3f3f, sizeof(segm));
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;

        update(i, x, segM, 1);
        update(i, x, segm, 0);
    }

    while (q--) {
        int a, b;
        cin >> a >> b;
        b++;
        int l = getVal(a, b, segm, 0);
        int r = getVal(a, b, segM, 1);
        cout << r - l << '\n';
    }


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}