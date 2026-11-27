#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

set<string> dp[10];

int n, c;
string oper(string s, int op) {
    if (op == 1) {
        for (auto& f : s) f = ('0' + '1' - f);
        return s;
    }
    if (op == 2) {
        for (int i = 0; i < s.size(); i += 2) {
            s[i] = ('0' + '1' - s[i]);
        }
        return s;
    }

    if (op == 3) {
        for (int i = 1; i < s.size(); i += 2) {
            s[i] = ('0' + '1' - s[i]);
        }
        return s;
    }

    for (int i = 0; i < s.size(); i += 3) {
        s[i] = ('0' + '1' - s[i]);
    }
    return s;
}

void solve() {

    cin >> n >> c;
    vector<int> on, off;
    int x;
    cin >> x;
    while (x != -1) {
        on.push_back(x);
        cin >> x;
    }

    cin >> x;
    while (x != -1) {
        off.push_back(x);
        cin >> x;
    }

    c = min(c, 5);
    string state(n, '1');
    dp[0].insert(state);

    for (int i = 1; i <= c; i++) {
        for (auto f : dp[i - 1]) {
            for (int k = 1; k <= 4; k++) {
                dp[i].insert(oper(f, k));
            }
        }
    }

    for (auto f : dp[c]) {
        bool ok = 1;
        for (auto ix : on) if (f[ix - 1] == '0') ok = 0;
        for (auto ix : off) if (f[ix - 1] == '1') ok = 0;

        if (ok) cout << f << '\n';
    }
    
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}