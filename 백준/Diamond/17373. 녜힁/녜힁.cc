#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fIdx[1000001], sIdx[1000001];
struct Q {
    ll ix1, k;
    ll idx;

    bool operator<(Q& o) {
        return make_pair(sIdx[ix1], k) < make_pair(sIdx[o.ix1], o.k);
    }
};

vector<ll> seg;

void update(int l, int r, int n, int u, int v) {
    if (l > u || r < u) return;
    if (l == u && r == u) {
        seg[n] += v;
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, u, v);
    update(m + 1, r, n * 2 + 1, u, v);
    seg[n] = seg[n * 2] + seg[n * 2 + 1];
}

int getIdx(int l, int r, int n, ll k) {
    if (seg[n] < k) return -1;
    if (l == r) return l;

    int m = (l + r) >> 1;
    if (k <= seg[n * 2]) return getIdx(l, m, n * 2, k);
    return getIdx(m + 1, r, n * 2 + 1, k - seg[n * 2]);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    ll n, m, q;
    cin >> n >> m >> q;

    vector<ll> A(n);
    for (auto& i : A) cin >> i;

    memset(fIdx, -1, sizeof(fIdx));
    memset(sIdx, -1, sizeof(sIdx));

    vector<int> cnt(m + 1);
    for (int i = 0; i < n; i++) {
        cnt[A[i]]++;
        fIdx[A[i]] = i;
        if (sIdx[A[i]] == -1) sIdx[A[i]] = i;
    }

    ll curr = 0;
    vector<ll> ans(m + 1), sA(m + 1);
    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) {
            curr++;
            ans[i] = m;
        }
    }

    for (int i = 0; i < n; i++) {
        if (fIdx[A[i]] == i) curr++;
        if (sIdx[A[i]] == i) ans[A[i]] = curr;
    }

    for (int i = 1; i <= m; i++) {
        sA[i] = sA[i - 1] + ans[i];
    }

    int sn = 1;
    while (sn <= m) sn *= 2;
    seg = vector<ll>(sn * 2);

    for (int i = 1; i <= m; i++) {
        if (cnt[i] == 0) update(0, sn - 1, 1, i, 1);
    }

    vector<pair<ll, ll>> res(q);
    vector<Q> query(q);
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;

        int ix1 = lower_bound(sA.begin(), sA.end(), x) - sA.begin();
        query[i].ix1 = ix1;
        query[i].k = x - sA[ix1 - 1];
        query[i].idx = i;
    }
    sort(query.begin(), query.end());

    //for (auto i : query) cout << i.ix1 << ' ' << i.k << ' ' << i.idx << '\n';

    int ix = 0, ix2 = 0;
    while (ix < q) {

        while (ix2 < n && ix2 <= sIdx[query[ix].ix1]) {
            // update
            if (fIdx[A[ix2]] == ix2) update(0, sn - 1, 1, A[ix2], 1);
            ix2++;
        }
        if (query[ix].ix1 > m) {
            res[query[ix].idx] = { -1, -1 };
        }
        else if (fIdx[query[ix].ix1] == -1) {
            res[query[ix].idx] = { query[ix].ix1, query[ix].k };
        }
        else {
            int ans1 = getIdx(0, sn - 1, 1, query[ix].k);
            res[query[ix].idx] = { query[ix].ix1, ans1 };
        }
        ix++;

    }

    for (int i = 0; i < q; i++) cout << res[i].first << ' ' << res[i].second << '\n';

}