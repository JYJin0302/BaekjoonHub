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

    int n;
    cin >> n;

    int curr = 1, d = 1;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        int x;
        cin >> x;

        bool go = 0;

        if (s[0] == 'H') {
            if (x == curr) {
                go = 0;
            }
            else {
                d *= -1;
            }

        }
        else {
            if (curr == x) go = 1;
        }

        cout << curr << ' ';
        if (go) cout << "YES\n";
        else cout << "NO\n";
        curr += d;
        curr = (curr + 11) % 12 + 1;
    }


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