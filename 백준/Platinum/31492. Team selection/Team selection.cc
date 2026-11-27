#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair


int seg[8484848];

void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }

    int md = (l + r) >> 1;
    update(l, md, n * 2, u, v);
    update(md + 1, r, n * 2 + 1, u, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int find(int l, int r, int n, int v) {
    if (l == r) return l;
    int md = (l + r) >> 1;
    int sz = (r - l + 1) >> 1;
    if (seg[n * 2] + v > sz) {
        return find(md+1, r, n * 2 + 1, v - (sz - seg[n*2]));
    }
    return find(l, md, n * 2, v);
}


void solve() {

    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        A[i * 2] = x;
    }
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        A[i * 2 + 1] = x;
    }

    int sn = 1;
    while (sn < n) sn *= 2;

    vector<int> ans;
    for (auto f : A) {
        int ix = find(0, sn - 1, 1, f);

        //cout << "Go: " << f << " +> " << ix << '\n';
        ans.push_back(ix + 1);
        update(0, sn - 1, 1, ix, 1);
    }

    for (int i = 0; i < n / 2; i++) cout << ans[i * 2] << ' ';
    cout << '\n';
    for (int i = 0; i < n / 2; i++) cout << ans[i * 2 + 1] << ' ';
    cout << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}