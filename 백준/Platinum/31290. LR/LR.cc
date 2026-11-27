#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const ll INF = 3e18;

ll n, k;
string s;
ll dp[27][1010][1010];
// 0 - 25 : 알파벳 , 26 : total

ll getDp(int c, int l, int r) {
    if (l == r) {
        if (s[l] - 'a' == c) return 2;
        return 0;
    }

    ll res = 0;
    if (s[l] - 'a' == c) {
        res += dp[26][l + 1][r];
    }
    if (s[r] - 'a' == c) {
        res += dp[26][l][r - 1];
    }
    if (res >= INF) res = INF;
    return res;
}

void solve() {

    cin >> n >> k >> s;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            for (int k = 0; k <= 26; k++) {
                dp[k][i][j] = 0;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; i + j < n; j++) {
            // [ i, i+j ]
            for (int k = 0; k < 26; k++) {
                ll res = getDp(k, j, j + i);
                dp[k][j][j + i] = res;

                dp[26][j][j + i] += res;
                if (dp[26][j][j + i] > INF) dp[26][j][j + i] = INF;
            }
        }
    }

    vector<pair<pair<int, int>, ll>> q, tmp;
    q.push_back(mp(mp(0, n - 1), 1));

    string ans;
    for (int i = 0; i < n; i++) {
        vector<ll> cnt(26);

        for (auto& [b, a] : q) {
            auto& [l, r] = b;
            for (int k = 0; k < 26; k++) {
                ll val = 0;
                if (INF / a < dp[k][l][r]) val = INF;
                else val = a * dp[k][l][r];
                cnt[k] += val;
                if (cnt[k] > INF) cnt[k] = INF;
            }
        }

        int nx = 0;
        while (nx < 26 && k > cnt[nx]) {
            k -= cnt[nx++];
        }
        ans += char('a' + nx);
        for (auto& [b, a] : q) {
            auto& [l, r] = b;
            if (s[l] - 'a' == nx) tmp.push_back(mp(mp(l + 1, r), a));
            if (s[r] - 'a' == nx) tmp.push_back(mp(mp(l, r - 1), a));
        }

        sort(all(tmp));
        q.clear();

        for (auto& f : tmp) {
            if (q.empty() || q.back().first != f.first) q.push_back(f);
            else q.back().second += f.second;
        }
        tmp.clear();
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}