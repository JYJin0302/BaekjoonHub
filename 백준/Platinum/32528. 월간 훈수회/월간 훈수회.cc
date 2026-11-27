#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()


void solve() {

    int n, a, b;
    cin >> n >> a>> b;
    vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i++) cin >> nxt[i];

    if (n & 1) {
        if (a != b) cout << "first\n";
        else cout << "second\n";
        return;
    }

    int t = 0;
    int cnt = 0;
    while (cnt < n * 3) {
        if (t == 0) {
            if (nxt[a] == b) {
                cout << "second\n";
                return;
            }
            a = nxt[a];
        }
        else {
            if (nxt[b] == a) {
                cout << "first\n";
                return;
            }
            b = nxt[b];
        }
        t ^= 1;
        cnt++;
    }
    cout << "draw\n";

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }

}