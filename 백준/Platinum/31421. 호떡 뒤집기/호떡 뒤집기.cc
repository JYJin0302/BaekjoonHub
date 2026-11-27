#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<pair<int, int>> range;
    int ix = 0;
    while (ix < n) {

        int tr = ix;
        while (tr < n && s[tr] == s[ix]) tr++;

        range.push_back(mp(ix, tr - 1));
        ix = tr;
    }

    int tn = range.size();

    if (tn == 1) {
        if (s[0] == 'B') cout << -1;
        else cout << 0;
        return;
    }
    if (tn == 2 && s[0] == 'W' && s[n-1] == 'B') {
        cout << -1;
        return;
    }

    if (s[0] == 'B') {
        cout << tn - 1 << '\n';
        for (int i = tn - 1; i > 0; i--) {
            cout << range[i].first << '\n';
        }
        return;
    }

    if (s[n - 1] == 'W') {
        cout << tn - 1 << '\n';
        for (int i = 0; i < tn - 1; i++) {
            cout << range[i].second+1 << '\n';
        }
        return;
    }

    cout << tn - 1 << '\n';
    cout << range[tn - 1].first << '\n' << range[tn - 3].first << '\n' << range[tn - 2].first << '\n';
    for (int i = 1; i < tn - 3; i++) {
        cout << range[i].first << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}