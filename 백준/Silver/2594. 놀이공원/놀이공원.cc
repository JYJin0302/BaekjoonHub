#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {    
    int n;
    cin >> n;

    vector<pair<int, int>> range;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;

        a = (a / 100) * 60 + a % 100;
        b = (b / 100) * 60 + b % 100;

        a = max(600, a - 10);
        b = min(1320, b + 10);
        range.push_back(mp(a, b));
    }
    range.push_back(mp(1320, 1320));
    sort(all(range));

    //for (auto f : range) cout << f.first << ' ' << f.second << '\n';

    int ans = 0;
    int pv = 600;
    for (auto&[a, b] : range) {
        if (a > pv) {
            ans = max(ans, a - pv);
        }
        pv = max(pv, b);
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}