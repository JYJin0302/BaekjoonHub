#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

void solve() {

    ll n;
    cin >> n;

    set<ll> ans;
    for (ll i = 2; i * i <= n; i++) {
        // test n base i

        ll tn = n;
        vector<ll> res;
        while (tn) {
            res.push_back(tn % i);
            tn /= i;
        }

        int sz = res.size();
        bool ok = 1;
        for (int f = 0; f < sz; f++) {
            if (res[f] != res[sz - 1 - f]) ok = 0;
        }

        if (ok) ans.insert(i);
    }

    ll tn = n;
    vector<ll> p;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            p.push_back(i);
            if (n / i != i) p.push_back(n / i);
        }
    }
    if (n != 1) p.push_back(n);
    n = tn;

    for (auto f : p) {
        if (f < n / f - 1) ans.insert(n / f - 1);
    }

    if (ans.empty()) cout << "*";
    else {
        for (auto f : ans) cout << f << ' ';
    }


}


int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}