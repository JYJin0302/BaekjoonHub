#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, L, a, b;
int seg[2002020];

void update(int x, int val) {
    for (x += L+1; x; x >>= 1) {
        seg[x] = min(seg[x], val);
    }
}

int getMin(int l, int r) {
    int res = 1e9;
    for (l += L+1, r += L+1; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> n >> L >> a >> b;
    a *= 2, b *= 2;

    vector<pair<int, int>> range(n);
    for (auto& i : range) {
        cin >> i.first >> i.second;
    }
    sort(all(range));

    vector<pair<int, int>> res;
    for (auto i : range) {
        if (res.empty()) res.push_back(i);
        else {
            if (res.back().second <= i.first) res.push_back(i);
            else res.back().second = max(res.back().second, i.second);
        }
    }

    vector<bool> ok(L + 1);
    int pv = 0;
    res.push_back(mp(L, L));
    for (auto f : res) {
        for (int x = pv; x <= f.first; x++) ok[x] = 1;
        pv = f.second;
    }

    for (int i = 0; i <= L * 2 + 10; i++) seg[i] = 1e9;

    update(0, 0);
    vector<int> ans(L + 1, -1);
    for (int i = a; i <= L; i++) {
        if (!ok[i] || i & 1) continue;
        int l = max(0, i - b);
        int r = i - a;

        int val = getMin(l, r + 1);
        update(i, val + 1);

        if (i == L) {
            if (val > L) cout << -1;
            else cout << val + 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
}