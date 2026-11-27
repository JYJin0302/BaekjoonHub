#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    string s;
    cin >> s;

    int n = s.size();
    int ix = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '+') {
            if (ix != -1) {
                cout << "No Money\n";
                return;
            }
            ix = i;
        }
    }
    if (ix == -1) {
        cout << "No Money\n";
        return;
    }

    string s1, s2;
    s1 = s.substr(0, ix);
    s2 = s.substr(ix + 1, n);
    bool ok = 1;
    if (s1 != s2) ok = 0;
    for (auto f : s1) if (!isdigit(f)) ok = 0;
    if (s1.empty()) ok = 0;
    else if (s1[0] == '0') ok = 0;

    if (ok) cout << "CUTE\n";
    else cout << "No Money\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}