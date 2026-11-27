#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int root[101010];
int L[101010];

vector<int> updList[101010];

int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

int seg[402020], lazy[402020];

void goLazy(int l, int r, int n) {
    if (lazy[n]) {
        seg[n] += lazy[n];
        if (l != r) {
            lazy[n * 2] += lazy[n];
            lazy[n * 2 + 1] += lazy[n];
        }
        lazy[n] = 0;
    }
}

void update(int l, int r, int n, int sl, int sr, int v) {
    goLazy(l, r, n);
    if (l > sr || r < sl)return;
    if (l >= sl && r <= sr) {
        lazy[n] += v;
        goLazy(l, r, n);
        return;
    }

    int m = (l + r) >> 1;
    update(l, m, n * 2, sl, sr, v);
    update(m + 1, r, n * 2 + 1, sl, sr, v);
    seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int getMax(int l, int r, int n, int sl, int sr) {
    goLazy(l, r, n);
    if (l > sr || r < sl)return 0;
    if (l >= sl && r <= sr) {
        return seg[n];
    }

    int m = (l + r) >> 1;
    return max(getMax(l, m, n * 2, sl, sr), getMax(m + 1, r, n * 2 + 1, sl, sr));
}

vector<int> num;
int getIdx(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin();
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> A(n);
    for (auto& i : A) {
        cin >> i;
        num.push_back(i);
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());

    int sz = num.size();

    for (int i = 0; i < n; i++) {
        updList[getIdx(A[i])].push_back(i);
    }

    vector<pair<int, pair<int, int>>> query;

    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {

        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;

        query.push_back(mp(c, mp(a, b)));
    }

    vector<pair<int, int>> md(q, mp(0, sz-1));

    vector<pair<int, pair<int, int>>> edge;
    for (int i = 1; i < n; i++) {
        edge.push_back(mp(min(A[i - 1], A[i]), mp(i - 1, i)));
    }
    sort(edge.rbegin(), edge.rend());

    int tn = 1;
    while (tn < n) tn *= 2;

    vector<int> ans(q, 1);
    while (1) {
        // PBS
        bool ck = 0;
        vector<vector<int>> qList(sz);
        for (int i = 0; i < q; i++) {
            if (md[i].first <= md[i].second) {
                qList[(md[i].first + md[i].second) / 2].push_back(i);
                ck = 1;
            }
        }

        if (!ck) break;

        for (int i = 0; i <= n; i++) {
            root[i] = i;
            L[i] = i;
        }
        for (int i = 0; i <= 2 * tn; i++) {
            lazy[i] = 0;
            seg[i] = 0;
        }

        int ix = 0;
        int currx = sz - 1;
        while (currx >= 0) {

            for (auto k : updList[currx]) {
                update(0, tn - 1, 1, k, k, 1);
            }

            while (ix < n-1 && edge[ix].first == num[currx]) {
                int u = edge[ix].second.first;
                int v = edge[ix].second.second;
                
                u = find(u), v = find(v);

                if (u != v) {
                    update(0, tn - 1, 1, L[v], v, u - L[u]+1);
                    root[u] = v;
                    L[v] = L[u];
                }
                ix++;
            }

            for (auto idx : qList[currx]) {
                int l = query[idx].second.first;
                int r = query[idx].second.second;
                int w = query[idx].first;

                int nl = l + w - 1;

                if (getMax(0, tn - 1, 1, nl, r) >= w) {
                    md[idx].first = currx + 1;
                    ans[idx] = num[currx];
                }
                else {
                    md[idx].second = currx - 1;
                }
            }
            currx--;
        }


    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';

}