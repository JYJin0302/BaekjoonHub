#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

struct Data {
    int l, r, idx;
};

void solve() {

    int n;
    cin >> n;

    ll p;
    cin >> p;

    vector<ll> e(n), k(n);
    for (auto& i : e) cin >> i;
    for (auto& i : k) cin >> i;
    vector<ll> s(n);
    for (int i = 0; i < n; i++) {
        s[i] = k[i] + (i ? k[i - 1] : 0);
    }

    vector<Data> A;
    int ans = 0;
    int r = -1;
    for (int i = 0; i < n; i++) {
        if (e[i] > p || r >= i) continue;

        ll cur = p + k[i];
        int tl = i, tr = i;
        while (1) {
            bool diff = 0;
            if (tl > 0 && e[tl-1] <= cur) {
                cur += k[--tl];
                diff = 1;
            }
            while (tr + 1 < n && e[tr+1] <= cur) {
                cur += k[++tr];
                diff = 1;
            }

            while (!A.empty() && A.back().idx >= tl) {
                int nl = A.back().l;
                A.pop_back();

                cur += (tl ? s[tl-1] : 0) - (nl ? s[nl-1] : 0);
                tl = nl;
            }

            if (!diff) break;
        }

        ans = max(ans, tr - tl + 1);
        A.push_back({ tl, tr ,i });
        r = tr;
    }
    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
