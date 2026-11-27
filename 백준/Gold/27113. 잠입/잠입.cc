#include <bits/stdc++.h>
using ll = long long;
using namespace std;

ll fastPow(ll b, ll ex, ll m) {
    ll res = 1;
    while (ex) {
        if (ex % 2) res = res * b % m;
        b = b * b % m;
        ex /= 2;
    }
    return res;
}

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };


void solve() {

    int n, m;
    cin >> n >> m;

    int curr = 1;
    bool ok = 1;

    for (int i = 0; i < n-1; i++) {
        int t;
        cin >> t;

        int x, x2;
        char c, c2;
        if (t == 1) {
            cin >> x >> c;

            if (c == 'L') {
                curr = max(curr, x + 1);
            }
            else if (curr >= x) ok = 0;
        }
        else if (t == 2) {
            cin >> x >> c;
            cin >> x2 >> c2;

            if (c == 'R' && c2 == 'L') {
                if (curr >= x) curr = max(curr, x2 + 1);
            }
            else {

                if (c == 'L') {
                    curr = max(curr, x + 1);
                }
                else if (curr >= x) ok = 0;

                if (c2 == 'L') {
                    curr = max(curr, x2 + 1);
                }
                else if (curr >= x2) ok = 0;

            }

        }
    }

    if (curr > m) ok = 0;
    if (ok) cout << "YES";
    else cout << "NO";

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}