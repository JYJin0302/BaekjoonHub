#include <bits/stdc++.h>
using namespace std;

struct Q {
    int l, r, idx;

    bool operator<(Q& o) {
        return l < o.l;
    }
};

int n;
vector<int> fw;

void update(int ix, int val) {
    while (ix <= n) {
        fw[ix] += val;
        ix += ix & -ix;
    }
}

int getSum(int ix) {
    int res = 0;
    while (ix) {
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    map<int, int> idx;
    vector<int> A(n+1);
    fw = vector<int>(n + 10);
    vector<pair<int, int>> tq;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        A[i] = idx[x];
        idx[x] = i;
        tq.push_back({A[i], i});
    }
    sort(tq.begin(), tq.end());

    //for (auto i : A) cout << i << ' ';

    int q;
    cin >> q;

    vector<Q> query(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        query[i] = { a, b, i };
    }

    sort(query.begin(), query.end());

    int tix = 0;
    vector<int> ans(q);
    for (auto i : query) {

        int l = i.l, r = i.r;
        while (tix < n && tq[tix].first < l) {
            update(tq[tix].second, 1);
            tix++;
        }

        int res = getSum(r) - getSum(l - 1);
        ans[i.idx] = res;
    }

    for (auto i : ans) cout << i << '\n';
}