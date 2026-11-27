#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool chk(char c) {
    string ts = "aeiouy";
    for (auto f : ts) if (f == c) return 1;
    return 0;
}

void solve() {

    string s1, s2;
    cin >> s1 >> s2;

    for (auto& i : s1) {
        if (i >= 'A' && i <= 'Z') i += ('a' - 'A');
    }
    for (auto& i : s2) {
        if (i >= 'A' && i <= 'Z') i += ('a' - 'A');
    }

    int ix = 0;
    for (int i = 0; i < s2.size(); i++) {
        if (ix < s1.size() && s1[ix] == s2[i]) {
            ix++;
        }
        else if (chk(s2[i])) {}
        else {
            cout << "Different\n";
            return;
        }
    }

    if (ix != s1.size()) cout << "Different\n";
    else cout << "Same\n";
}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}