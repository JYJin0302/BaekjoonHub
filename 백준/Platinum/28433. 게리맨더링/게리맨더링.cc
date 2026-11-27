#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {

    int n;
    cin >> n;

    vector<ll> A;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;

        if (x == 0) continue;
        if (A.empty()) A.push_back(x);
        else {
            if (x < 0) {
                if (A.back() < 0) A.back() += x;
                else {
                    if (A.back() + x > 0) A.back() += x;
                    else A.push_back(x);
                }
            }
            else {
                if (A.back() < 0 && A.back() + x > 0) {
                    A.back() += x;
                }
                else A.push_back(x);
            }
        }

        /*cout << "CURR: ";
        for (auto j : A) cout << j << ' ';
        cout << '\n';*/
    }

    int cnt1 = 0, cnt2 = 0;
    for (auto i : A) {
        if (i > 0) cnt1++;
        else cnt2++;
    }

    if (cnt1 > cnt2) {
        cout << "YES\n";
    }
    else cout << "NO\n";

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}