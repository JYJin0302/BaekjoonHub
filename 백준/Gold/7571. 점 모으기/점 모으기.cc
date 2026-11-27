#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, m;
    cin >> n >> m;
    
    vector<int> xpos, ypos;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        xpos.push_back(a);
        ypos.push_back(b);
    }

    sort(all(xpos));
    sort(all(ypos));

    int tx = xpos[m / 2];
    int ty = ypos[m / 2];

    ll ans = 0;
    for (auto f : xpos) {
        ans += abs(f - tx);
    }
    for (auto f : ypos) {
        ans += abs(f - ty);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}