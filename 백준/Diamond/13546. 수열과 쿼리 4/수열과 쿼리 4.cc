#include <bits/stdc++.h>
using namespace std;

int n, k, sn;
struct Q {
    int s, e, idx;

    bool operator<(Q& a) {
        if (s / sn == a.s / sn) return e < a.e;
        return s / sn < a.s / sn;
    }
};

int A[101010];
list<int> pos[101010];
int cnt[101010];
int cntB[5000];

void add_num(int idx) {
    int v = A[idx];
    if (pos[v].size() >= 2) {
        int v1 = pos[v].back() - pos[v].front();
        cnt[v1]--;
        cntB[v1 / sn]--;
    }

    if (pos[v].empty()) {
        pos[v].push_back(idx);
        return;
    }
    if (pos[v].front() > idx) pos[v].push_front(idx);
    else pos[v].push_back(idx);
    if (pos[v].size() >= 2) {
        int v1 = pos[v].back() - pos[v].front();
        cnt[v1]++;
        cntB[v1 / sn]++;
    }
}

void sub_num(int idx) {
    int v = A[idx];
    if (pos[v].size() == 1) {
        pos[v].pop_back();
        return;
    }
    int v1 = pos[v].back() - pos[v].front();
    cnt[v1]--;
    cntB[v1 / sn]--;
    if (pos[v].front() == idx) pos[v].pop_front();
    else pos[v].pop_back();

    if (pos[v].size() >= 2) {
        int v1 = pos[v].back() - pos[v].front();
        cnt[v1]++;
        cntB[v1 / sn]++;
    }
}

int getMax() {
    int res = 0;
    int mx = n / sn;
    while(mx >= 0){
        if (cntB[mx]) break;
        mx--;
    }
    if (mx == -1) return 0;

    int l = sn * mx;
    int r = min(n, l + sn);
    for (int i = r; i >= l; i--) {
        if (cnt[i]) return i;
    }
    return 0;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> k;
    sn = 300;
    for (int i = 1; i <= n; i++) cin >> A[i];

    int t;
    cin >> t;
    vector<Q> q(t);
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        q[i].s = a, q[i].e = b;
        q[i].idx = i;
    }
    sort(q.begin(), q.end());

    vector<int> ans(t);

    int l = q[0].s, r = q[0].e;
    for (int i = l; i <= r; i++) {
        add_num(i);
    }
    ans[q[0].idx] = getMax();

    for (int k = 1; k < t; k++) {
        Q i = q[k];
        int ql = i.s, qr = i.e;
        for (int j = l - 1; j >= ql; j--) add_num(j);
        for (int j = r + 1; j <= qr; j++) add_num(j);
        for (int j = l; j < ql; j++) sub_num(j);
        for (int j = r; j > qr; j--) sub_num(j);
        ans[i.idx] = getMax();
        l = ql, r = qr;
    }

    for (auto i : ans) cout << i << '\n';
}