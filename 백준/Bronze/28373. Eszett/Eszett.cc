#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair


void solve() {

    string s;
    cin >> s;

    for (auto& f : s) f = tolower(f);
    cout << s << '\n';

    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == 's' && s[i - 1] == 's') {
            cout << s.substr(0, i - 1) << 'B' << s.substr(i + 1, n) << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}