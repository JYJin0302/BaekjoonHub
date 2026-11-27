#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

int MN = 300030;
int seg[606060];
void update(int ix, int val) {
    for (ix += MN; ix; ix >>= 1) {
        seg[ix] += val;
    }
}

int getS(int l, int r) {
    int res = 0;
    for (l += MN, r += MN; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res += seg[l++];
        if (r & 1) res += seg[--r];
    }
    return res;
}

void solve() {

    int n;
    cin >> n;
    vector<int> P(n + 1);
    for (int i = 2; i <= n; i++) cin >> P[i];

    int q;
    cin >> q;

    vector<pair<pair<int, int>, int>> Q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        Q.push_back(mp(mp(r, l), i));
    }
    sort(all(Q));

    int cur = 1;
    vector<int> ans(q);
    for (auto f : Q) {
        auto [r, l] = f.x;
        while (cur <= r) {
            update(P[cur], 1);
            cur++;
        }

        ans[f.y] = r - l + 1 - getS(l, r + 1);
    }
    for (auto f : ans) cout << f << '\n';

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}