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

    int ix = find(all(s), 'O') - s.begin();

    int l = 0, r = 0, rem = 0;
    for (l = ix-1; l >=0; l--){
        if (s[l] == 'X') break;
    }
    for (r = ix + 1; r < n; r++) {
        if (s[r] == 'X') break;
    }

    for (int i = 0; i < n; i++) {
        if (i >= l && i <= r) continue;
        if (s[i] == '.') rem++;
    }

    l = ix - l - 1;
    r = r - ix - 1;
    if (l > r) swap(l, r);
    rem %= 2;

    if (l == 0) {
        cout << "mingyu\n";
        return;
    }

    if (l == 1 && r == 1) {
        if (rem == 1) cout << "mingyu\n";
        else cout << "yunsu\n";
        return;
    }
    else if (l == 1) {
        int tmp = r - l - 1 + rem;
        if (tmp % 2 == 0) {
            cout << "mingyu\n";
        }
        else {
            cout << "draw\n";
        }
        return;
    }
    cout << "draw\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}