#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<ll> tmp;

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<ll> ans;
    while (k) {
        int ix = lower_bound(all(tmp), k + 1) - tmp.begin() - 1;
        ans.push_back(tmp[ix]);
        k -= tmp[ix];
    }

    cout << ans.size() << '\n';
    for (auto f : ans) cout << f << ' ';
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 1; i <= 9; i++) {
        ll v = i;
        for (int j = 0; j < 17; j++) {
            tmp.push_back(v);
            v = v * 10 + i;
        }
    }
    sort(all(tmp));
    tmp.push_back(2e18);

    int t = 1;
     cin >> t;
    while (t--) solve();
}