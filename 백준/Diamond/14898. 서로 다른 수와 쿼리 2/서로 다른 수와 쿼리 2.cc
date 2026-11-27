#include <bits/stdc++.h>
using namespace std;

const int sz = 1 << 20;
vector<int> Mst[sz * 2];

void init(int n) {
    if (n >= sz) return;

    init(n * 2), init(n * 2 + 1);
    Mst[n].resize(Mst[n * 2].size() + Mst[n * 2 + 1].size());
    merge(Mst[n * 2].begin(), Mst[n * 2].end(), Mst[n * 2 + 1].begin(), Mst[n * 2 + 1].end(), Mst[n].begin());
}

int solve(int l, int r, int n, int sl, int sr, int k) {
    if (l > sr || r < sl) return 0;
    if (l >= sl && r <= sr) {
        int ix = lower_bound(Mst[n].begin(), Mst[n].end(), k) - Mst[n].begin();
        return ix;
    }

    int m = (l + r) >> 1;
    return solve(l, m, n * 2, sl, sr, k) + solve(m + 1, r, n * 2 + 1, sl, sr, k);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    map<int, int> idx;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        Mst[i+sz].push_back(idx[x]);
        idx[x] = i;    
    }

    init(1);
    int q;
    cin >> q;

    int q0 = 0;
    while (q--) {

        int a, b;
        cin >> a >> b;

        a += q0;

        q0 = solve(0, sz - 1, 1, a, b, a);
        cout << q0 << '\n';

    }

}