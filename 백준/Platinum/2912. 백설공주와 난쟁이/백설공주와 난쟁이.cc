#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pi = pair<int, int>;
#define mp make_pair
#define all(x) x.begin(), x.end()

int n, c, sn;
struct Q {
    int l, r;
    int idx;
    bool operator<(Q& o) {
        if (l / sn == o.l / sn) return r < o.r;
        return l / sn < o.l / sn;
    }
};

int cnt[10101];

void solve() {

    cin >> n >> c;
    sn = sqrt(n);

    vector<int> col(n);
    for (auto& i : col) cin >> i;

    int q;
    cin >> q;
    vector<Q> qur;
    for (int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        qur.push_back({ a, b, i });
    }
    sort(all(qur));

    int l = -1, r = -1;
    vector<int> ans(q);
    for (const auto& f : qur) {
        int nl = f.l, nr = f.r;

        if (l == -1) {
            for (int i = nl; i <= nr; i++) cnt[col[i]]++;
        }
        else {
            for (int i = r + 1; i <= nr; i++) cnt[col[i]]++;
            for (int i = r; i > nr; i--) cnt[col[i]]--;

            for (int i = l; i < nl; i++) cnt[col[i]]--;
            for (int i = l - 1; i >= nl; i--) cnt[col[i]]++;
        }
        l = nl, r = nr;

        int len = r - l + 1;
        for (int i = 1; i <= c; i++) {
            if (cnt[i] > len / 2) {
                ans[f.idx] = i;
                break;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i]) {
            cout << "yes " << ans[i] << '\n';
        }
        else cout << "no\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}