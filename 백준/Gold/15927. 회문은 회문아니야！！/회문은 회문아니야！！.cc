#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    string s;
    cin >> s;

    int n = s.size();
    if (s == string(n, s[0])) {
        cout << -1;
        return;
    }

    int l = -1, r = -1;
    bool ok = 1;
    // check [0, n-1]
    ok = 1;
    l = 0, r = n - 1;
    while (l < r) {
        if (s[l] != s[r]) {
            ok = 0;
            break;
        }
        l++, r--;
    }
    if (!ok) {
        cout << n;
        return;
    }

    cout << n - 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}