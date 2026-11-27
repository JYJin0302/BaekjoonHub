#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    pair<int, pair<int, int>> ans = mp(0, mp(-1, -1));
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            int x;
            cin >> x;
            ans = max(ans, mp(x, mp(i, j)));
        }
    }
    cout << ans.first << '\n' << ans.second.first << ' ' << ans.second.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}