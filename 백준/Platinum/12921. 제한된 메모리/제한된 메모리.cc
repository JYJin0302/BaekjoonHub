#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int find_idx(int n, vector<pair<int, int>>& v) {

    int l = 0, r = v.size();

    int res = r;
    while (l <= r) {
        int m = (l + r) / 2;

        if (v[m].first >= n) {
            r = m - 1;
            res = m;
        }
        else l = m + 1;
    }
    return res;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, x, a, b;
    cin >> n >> x >> a >> b;

    const ll mod = 1e9 + 7;

    int q;
    cin >> q;

    vector<int> A(q);
    for (auto& i : A) cin >> i;

    vector<pair<int, int>> mx(q), ans(q);
    for (int i = 0; i < q; i++) {
        mx[i] = { (mod - 1) / 2, i };
        ans[i] = { 0, mod - 1 };
    }

    while (!mx.empty()) {
        int sz = mx.size();

        vector<int> cnt(sz + 1);

        ll tmp = x;
        for (int i = 0; i < n; i++) {
            // tmp operation
            int ix = find_idx(tmp, mx);
            cnt[ix]++;

            tmp = (tmp * a + b) % mod;
        }

        for (int i = 0; i < sz; i++) {
            int ta, tb;
            tie(ta, tb) = mx[i];

            if (i > 0) cnt[i] += cnt[i - 1];

            if (cnt[i] >= A[tb] + 1) {
                // r->mid
                ans[tb].second = ta;
            }
            else {
                // l->mid
                ans[tb].first = ta;
            }
        }

        mx.clear();
        for (int i = 0; i < q; i++) {
            if (ans[i].first + 1 != ans[i].second) {
                mx.push_back({ (ans[i].first + ans[i].second) / 2, i });
            }
        }
        sort(mx.begin(), mx.end());
    }

    ll res = 0;
    for (int i = 0; i < q; i++) {
        res += ans[i].second;
    }
    cout << res;
}