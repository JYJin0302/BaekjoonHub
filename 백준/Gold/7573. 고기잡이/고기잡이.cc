#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n, m, l;
    cin >> n >> l >> m;

    vector<pair<int, int>> fish;
    vector<int> xpos, ypos;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        fish.push_back(mp(a, b));
        xpos.push_back(a);
        ypos.push_back(b);
    }

    sort(all(xpos));
    xpos.erase(unique(all(xpos)), xpos.end());
    sort(all(ypos));
    ypos.erase(unique(all(ypos)), ypos.end());

    int ans = 0;
    for (auto x : xpos) {
        for (auto y : ypos) {
            for (int dx = 1; dx <= l / 2 - 1; dx++) {
                int dy = l / 2 - dx;

                int cnt = 0;
                for (auto& [a, b] : fish) {
                    if (a >= x && a <= x + dx && b >= y && b <= y + dy) cnt++;
                }
                ans = max(ans, cnt);
            }
        }
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}