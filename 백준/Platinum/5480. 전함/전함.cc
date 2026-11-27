#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int N, K, L;
struct Ship {
    int x1, y1, x2, y2, w;
};

vector<int> num;
int getIdx(int x) {
    return lower_bound(all(num), x) - num.begin();
}

int seg[202020]; // minimum
void update(int u, int x) {
    for (u += L; u; u >>= 1) {
        seg[u] = min(seg[u], x);
    }
}

int getMin(int l, int r) {
    int res = 1e7;
    for (l += L, r += L; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = min(res, seg[l++]);
        if (r & 1) res = min(res, seg[--r]);
    }
    return res;
}

void solve() {

    cin >> N >> K >> L;

    num.clear();
    vector<Ship> A(K);
    for (auto& [a, b, c, d, e] : A) {
        cin >> a >> b >> c >> d >> e;
        if (a > c) swap(a, c);
        if (b > d) swap(b, d);
    }

    vector<pair<int, int>> q(L);
    for (auto& i : q) {
        cin >> i.first >> i.second;
        num.push_back(i.first);
    }

    sort(all(num));
    num.erase(unique(all(num)), num.end());

    for (int i = 0; i < L * 2 + 10; i++) seg[i] = 1e7;

    vector<int> getShot(K, L+10);
    vector<int> ans(L);
    // x axis
    for (int i = 0; i < L; i++) {
        auto& [a, b] = q[i];
        if (b == 1) {
            int ta = getIdx(a);
            update(ta, i);
        }
    }
    for (int i = 0; i < K; i++) {
        int l = A[i].x1, r = A[i].x2;

        l = lower_bound(all(num), l) - num.begin();
        r = upper_bound(all(num), r) - num.begin();

        int res = getMin(l, r);
        if (res != 1e7) {
            getShot[i] = min(getShot[i], res);
        }
    }
    for (int i = 0; i < L * 2 + 10; i++) seg[i] = 1e7;
    // y axis
    for (int i = 0; i < L; i++) {
        auto& [a, b] = q[i];
        if (b == 0) {
            int ta = getIdx(a);
            update(ta, i);
        }
    }
    for (int i = 0; i < K; i++) {
        int l = A[i].y1, r = A[i].y2;
        l = lower_bound(all(num), l) - num.begin();
        r = upper_bound(all(num), r) - num.begin();
        int res = getMin(l, r);
        if (res != 1e7) {
            getShot[i] = min(getShot[i], res);
        }
    }

    for (int i = 0; i < K; i++) {
        if (getShot[i] != L + 10) {
            ans[getShot[i]] = max(ans[getShot[i]], A[i].w);
        }
    }


    for (auto& i : ans) cout << i << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) solve();
}