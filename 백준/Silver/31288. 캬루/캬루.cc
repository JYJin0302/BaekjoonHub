#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n;
    string s;
    cin >> n >> s;

    if (n == 1) {
        cout << "4 2\n";
        return;
    }

    int val = 0;
    for (auto f : s) val += f - '0';
    val %= 3;

    val = 3 - val;
    for (int i = 0; i < n; i++) {
        int c = s[i] - '0';

        int nc = c + val;
        if (nc >= 10) nc -= 3;

        s[i] = char(nc + '0');
        cout << s << ' ' << 3 << '\n';
        s[i] = char(c + '0');
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    cin >> t;
    while(t--) solve();
}