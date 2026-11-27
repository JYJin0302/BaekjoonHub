#include<bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v, val;

    bool operator<(Edge& o) {
        return val > o.val;
    }
};

struct Q {
    int k;
    int idx;

    bool operator<(Q& o) {
        return k > o.k;
    }
};

int root[300010];
bool isLine[300010];
bool isCycle[300010];

int find(int n) {
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

int cnt[300010];
int cnt_num[300010];

void addNum(int v) {
    int curr = cnt[v];
    cnt_num[curr]--;
    cnt_num[curr + 1]++;
    cnt[v]++;
}

void subNum(int v) {
    int curr = cnt[v];
    cnt_num[curr]--;
    cnt_num[curr - 1]++;
    cnt[v]--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> lE(n + 1), rE(n + 1);

    for (int i = 1; i <= n; i++) {
        root[i] = i;
        isLine[i] = 1;
        lE[i] = i;
        rE[i] = i;
    }

    vector<Edge>A(m);
    for (auto& i : A) {
        cin >> i.u >> i.v >> i.val;
    }

    int q;
    cin >> q;
    vector<Q>query(q);
    for (int i = 0; i < q; i++) {
        cin >> query[i].k;
        query[i].idx = i;
    }

    sort(A.begin(), A.end());
    sort(query.begin(), query.end());
    cnt_num[0] = n;

    int ix1 = 0, ix2 = 0;
    int cntCycle = 0;
    vector<pair<int, int>> ans(q);
    while (ix2 < q) {
        int v1 = -1, v2 = -1;
        if (ix1 < m) v1 = A[ix1].val;
        v2 = query[ix2].k;

        if (v2 > v1) {
            // query
            int ans1 = n, ans2 = ix1;
            ans1 -= cnt_num[0] + cnt_num[2] - cntCycle;
            ans2 -= cnt_num[2] - cntCycle;
            ans[query[ix2].idx] = { ans1, ans2 };
            ix2++;
        }
        else {
            // update

            int u = A[ix1].u, v = A[ix1].v;
            int fu = find(u);
            int fv = find(v);
            addNum(u);
            addNum(v);

            if (isCycle[fu] || isCycle[fv]) {
                if (isCycle[fu]) {
                    cntCycle--;
                    isCycle[fu] = 0;
                }
                if (isCycle[fv]) {
                    cntCycle--;
                    isCycle[fv] = 0;
                }
                isLine[fu] = 0;
                isLine[fv] = 0;
            }
            else if (isLine[fu] && isLine[fv]) {
                bool ok = 1;
                if (rE[fu] == u || lE[fu] == u) {}
                else ok = 0;
                if (rE[fv] == v || lE[fv] == v) {}
                else ok = 0;
                if (ok) {
                    int u2 = rE[fu] + lE[fu] - u;
                    int v2 = rE[fv] + lE[fv] - v;
                    if (fu == fv) {
                        isCycle[fu] = 1;
                        cntCycle++;
                        isLine[fu] = 0;
                    }
                    else {
                        isLine[fu] = 1;
                        isLine[fv] = 0;
                        rE[fu] = u2;
                        lE[fu] = v2;
                    }
                }
                else {
                    isLine[fu] = 0;
                    isLine[fv] = 0;
                }

            }
            else {
                isLine[fu] = 0;
                isLine[fv] = 0;
            }
            root[fv] = fu;
            ix1++;
        }
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i].first << ' ' << ans[i].second << '\n';
    }

}
