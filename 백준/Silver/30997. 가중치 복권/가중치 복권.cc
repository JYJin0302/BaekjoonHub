#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll pwl(ll b, ll ex) {
    ll res = 1;
    while (ex--) {
        res *= b;
    }
    return res;
}

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<ll> cnt(n + 1);
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < 3; j++) {
            int x;
            cin >> x;
            cnt[x]++;
        }
    }
    ll p = 0, q = 1;
    tuple<int, int, int> ans = { 0, 0, 0 };

    for (int i = 1; i <= n; i++) {
        cnt[i]++;
        for (int j = i + 1; j <= n; j++) {
            cnt[j]++;
            for (int w = j + 1; w <= n;w++) {
                cnt[w]++;

                ll np = 0, nq = 1;

                ll tot = 3*m;
                ll rem = tot - cnt[i] - cnt[j] - cnt[w];
                np = pwl(rem, k);
                np *= cnt[i] + cnt[j] + cnt[w];
                nq = pwl(tot, k+1);

                if (p <= np) {
                    p = np, q = nq;
                    ans = make_tuple(i, j, w);
                }
                cnt[w]--;
            }
            cnt[j]--;
        }
        cnt[i]--;
    }

    ll g = gcd(p, q);
    p /= g, q /= g;
    cout << p << ' ' << q << '\n';
    auto& [a, b, c] = ans;
    cout << a << ' ' << b << ' ' << c;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
