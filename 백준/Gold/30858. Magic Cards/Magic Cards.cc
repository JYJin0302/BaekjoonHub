#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

const ll mod = 998244353;
const ll mod2 = 1e9 + 7;
pair<ll, ll> pw2[101];

pair<ll, ll> val[501010];
map<pair<ll, ll>, ll> cnt, ans;

void solve() {

    pw2[0] = mp(1, 1);
    for (int i = 1; i <= 100; i++) {
        pw2[i].first = pw2[i - 1].first * 2 % mod;
        pw2[i].second = pw2[i - 1].second * 2 % mod2;
    }

    int n, k, m, q;
    cin >> n >> k >> m >> q;
    for (int i = 0; i < k; i++) {
        vector<int> tmp(m);
        for (auto& f : tmp) cin >> f;

        sort(tmp.begin(), tmp.end());
        tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

        for (auto x : tmp){
            val[x].first = (val[x].first + pw2[i].first) % mod;
            val[x].second = (val[x].second + pw2[i].second) % mod2;
        }
    }

    for (int i = 1; i <= n; i++) {
        cnt[val[i]]++;
        ans[val[i]] = i;
    }

    while (q--) {
        string s;
        cin >> s;

        pair<ll, ll> res = mp(0, 0);
        for (int i = 0; i < k; i++) {
            if (s[i] == 'Y') {
                res.first = (res.first + pw2[i].first) % mod;
                res.second = (res.second + pw2[i].second) % mod2;
            }
        }

        if (cnt[res] == 1) cout << ans[res] << '\n';
        else cout << 0 << '\n';
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
