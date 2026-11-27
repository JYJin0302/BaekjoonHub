#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second


void solve() {

    int n, m;
    cin >> n >> m;

    string s1, s2;
    cin >> s1 >> s2;

    vector<bool> dir(26);
    for (auto f : s1) dir[f - 'A'] = 1;

    reverse(all(s1));
    int t;
    cin >> t;

    string s = s1 + s2;

    while (t--) {

        int ix = 0;
        while (ix + 1 < s.size()) {
            if (dir[s[ix] - 'A'] && !dir[s[ix + 1] - 'A']) {
                swap(s[ix], s[ix + 1]);
                ix += 2;
            }
            else ix++;
        }

    }
    cout << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}