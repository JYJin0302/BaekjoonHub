#include <bits/stdc++.h>
using namespace std;

int sn;
struct Q {
    int l, r, idx;

    bool operator< (Q& other) {
        if (l / sn == other.l / sn) return r < other.r;
        return l / sn < other.l / sn;
    }
};

int A[100001];
int cnt[200010], cnt2[200010];
int ans = 0;

void addNum(int x) {
    cnt[x]++;
    cnt2[cnt[x]]++;
    cnt2[cnt[x] - 1]--;
    ans = max(ans, cnt[x]);
}

void delNum(int x) {
    cnt[x]--;
    cnt2[cnt[x] + 1]--;
    cnt2[cnt[x]]++;
    if (cnt2[ans] == 0) ans--;
}

void solve(int n) {

    sn = sqrt(n);
    int q;
    cin >> q;

    for (int i = 0; i < n; i++) {
        cin >> A[i];
        A[i] += 100000;
    }

    vector<Q> query(q);
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        query[i] = { a, b, i };
    }
    sort(query.begin(), query.end());

    ans = 0;
    int s = query[0].l, e = query[0].r;
    for (int i = s; i <= e; i++) {
        addNum(A[i]);
    }
    vector<int> res(q);
    res[query[0].idx] = ans;

    for (int i = 1; i < q; i++) {

        int ns = query[i].l, ne = query[i].r;
        for (int j = ns; j < s; j++) addNum(A[j]);
        for (int j = e + 1; j <= ne; j++) addNum(A[j]);

        for (int j = s; j < ns; j++) delNum(A[j]);
        for (int j = ne + 1; j <= e; j++) delNum(A[j]);

        res[query[i].idx] = ans;
        s = ns;
        e = ne;
    }

    for (int i = s; i <= e; i++) delNum(A[i]);

    for (auto i : res) cout << i << '\n';
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t) {
        solve(t);
        cin >> t;
    }

}