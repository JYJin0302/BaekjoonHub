#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

#define YES cout << "Valid Password\n"
#define NO cout << "Invalid Password\n"

void solve() {

    string s;
    cin >> s;

    int n = s.size();

    if (n < 9 || n > 20) {
        NO;
        return;
    }

    for (int i = 2; i < n; i++) {
        if (s[i] == s[i - 1] && s[i] == s[i - 2]) {
            NO;
            return;
        }
    }

    int lc = 0, uc = 0, dg = 0, non = 0;
    string ts;
    for (auto f : s) {
        if (isdigit(f)) {
            dg++;
            ts += f;
        }
        else if (isalpha(f)) {
            ts += f;
            if (f >= 'A' && f <= 'Z') uc++;
            else lc++;
        }
        else {
            non++;
        }
    }
    if (lc < 2 || uc < 2 || dg < 1 || non < 2) {
        NO;
        return;
    }

    for (auto& f : ts) if (isalpha(f)) f = tolower(f);

    // palindrome

    int l = 0, r = ts.size() - 1;
    bool ok = 0;
    while (l < r) {
        if (ts[l] != ts[r]) {
            ok = 1;
            break;
        }
        l++, r--;
    }

    if (!ok) {
        NO;
        return;
    }

    vector<string> test = { "password", "code", "virginia", "cavalier" };
    for (int i = 0; i < 4; i++) {
        string tmp = test[i];
        reverse(all(tmp));
        test.push_back(tmp);
    }

    for (auto f : test) {
        int ix = 0;
        int i2 = 0;
        while (ix < f.size() && i2 < ts.size()) {
            if (ts[i2] == f[ix]) {
                ix++, i2++;
            }
            else i2++;
        }

        if (ix == f.size()) {
            NO;
            return;
        }
    }

    YES;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
}