#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;

    vector<int> ans = { 1 };

    for (int i = 2; i <= n; i++) {
        int tot = i * (i - 1) / 2;
        pair<int, int> res = mp(1, 0);
        int ss = 0;
        for (int j = 0; j < ans.size(); j++) {
            ss += ans[j];
            int nv = 0;
            if (ss < tot - ss) nv = ss * 2 + 1;
            else nv = 2 * (tot - ss);
            res = max(res, mp(nv, j + 1));
        }

        for (auto& f : ans)f++;
        ans.insert(ans.begin() + res.second, 1);
    }
    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}