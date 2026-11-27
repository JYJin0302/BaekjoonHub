#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using ld = long double;

#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {
    ld x;
    int k;
    cin >> x >> k;
    vector<ld> A(k);
    for (auto& i : A) cin >> i;
    for (auto& i : A) i = 1 / i;
    sort(all(A));

    set<pair<ld, ld>> st;

    vector<pair<ld, ld>> res;
    res.push_back(mp(1, A[k-1]));

    while (1) {
        if (st.empty() || (*st.begin()).first > res.back().second * A[0]) {
            ld nl = res.back().second;
            ld nr = nl * A[0];

            for (auto f : A) {
                st.insert(mp(nl * f, nr * f));
                if (nl * f > x) break;
            }
            continue;
        }

        auto [a, b] = *st.begin();
        st.erase(st.begin());

        if (res.back().second >= a) {
            res.back().second = max(res.back().second, b);
        }
        else {
            ld nl = res.back().second;
            ld nr = a;
            for (auto f : A) {
                 st.insert(mp(nl * f, nr * f));
                 if (nl * f > x) break;
            }
            res.push_back(mp(a, b));
        }

        if (a > x) break;

    }

    bool ok = 0;
    for (auto &[l, r] : res) {
        if (l < x && x <= r) ok = 1;
    }

    if (ok) cout << "Nils\n";
    else cout << "Mikael\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}