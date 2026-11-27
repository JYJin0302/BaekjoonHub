#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define x first
#define y second
#define mp make_pair

void solve() {

    int n, k;
    cin >> n >> k;
    vector<int> A(n);
    for (auto& i : A) cin >> i;

    vector<int> pos(k + 1);
    for (int i = 0; i < n; i++) {
        pos[A[i]] = i;
    }

    set<pair<int, int>> st, dp;

    for (int i = 1; i <= k; i++) st.insert(mp(pos[i], i));

    vector<int> ans;
    vector<bool> used(k + 1);
    int ix = 0;
    int pv = -1;
    for (int i = 0; i < k; i++) {
        while (!st.empty() && used[(*st.begin()).y]) st.erase(st.begin());

        int lim = (*st.begin()).x;
        while (ix <= lim) {
            dp.insert(mp(A[ix], ix));
            ix++;
        }

        while (!dp.empty()) {
            auto [a, b] = *dp.begin();
            if (used[a] || b <= pv) {
                dp.erase(dp.begin());
            }
            else break;
        }

        auto [a, b] = *dp.begin();
        ans.push_back(a);
        used[a] = 1;
        pv = b;
    }

    for (auto f : ans) cout << f << ' ';
    cout << '\n';

}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}