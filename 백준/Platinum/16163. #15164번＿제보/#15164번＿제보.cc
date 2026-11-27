#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> get(string& s) {
    // string -> $s#t#r#i#n#g@
    int n = s.length();
    vector<char> a(2 * n + 1, '#');
    vector<int> d(2 * n + 1);
    a[0] = '$';
    a.back() = '@';
    for (int i = 0; i < n; i++) {
        a[2 * i + 1] = s[i];
    }
    int l = 0, r = 1;
    for (int i = 0; i <= 2 * n; i++) {
        if (i <= r) {
            d[i] = min(r - i, d[l + r - i]);
        }
        while (a[i + d[i]] == a[i - d[i]]) { ++d[i]; }
        if (i + d[i] > r) {
            l = i - d[i];
            r = i + d[i];
        }
    }
    for (int i = 0; i <= 2 * n; i++) {
        if (i % 2) {
            if (d[i] % 2 == 0) { --d[i]; }
        }
        else {
            if (d[i] % 2) { --d[i]; }
        }
    }
    return d;
}

void solve() {

    string s;
    cin >> s;
    ll ans = 0;
    vector<int> M = get(s);
    for (int i = 1; i < M.size()-1; i++) {
        ans += (M[i] + 1) / 2;
    }
    cout << ans;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) solve();
}