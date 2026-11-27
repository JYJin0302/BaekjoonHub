#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool pre[2][202020];
bool suf[2][202020];

void solve() {

    int n, m;
    cin >> n >> m;

    vector<string> A(n);
    for (auto& i : A) cin >> i;

    for (int i = 0; i < n; i += 2) {
        pre[0][i] = 0;
        pre[1][i] = (A[i][0] == 't');

        if (i) {
            if (A[i - 1][0] == 'o') {
                pre[0][i] = pre[1][i - 2] || pre[0][i - 2];
            }
            else {
                pre[1][i] = pre[1][i] && pre[1][i - 2];
                pre[0][i] = pre[0][i - 2];
            }
        }
    }

    for (int i = n - 1; i >= 0; i -= 2) {
        suf[0][i] = 0;
        suf[1][i] = (A[i][0] == 't');

        if (i + 2 < n) {
            if (A[i + 1][0] == 'o') {
                suf[0][i] = suf[1][i + 2] || suf[0][i + 2];
            }
            else {
                suf[1][i] = suf[1][i] && suf[1][i + 2];
                suf[0][i] = suf[0][i + 2];
            }
        }
    }

    /*for (int i = 0; i < n; i += 2) {
        cout << pre[0][i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i += 2) {
        cout << pre[1][i] << ' ';
    }
    cout << '\n';
    cout << '\n';
    for (int i = 0; i < n; i += 2) {
        cout << suf[0][i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; i += 2) {
        cout << suf[1][i] << ' ';
    }
    cout << '\n';*/
    string ans;
    while (m--) {
        int a, b;
        cin >> a >> b;
        string s;
        cin >> s;

        a--, b--;

        if (a == 0 && b == n - 1) {
            ans += 'Y';
            continue;
        }

        bool ok = 1;
        if (a == 0) {
            bool t1 = A[b + 1][0] == 'a';
            if (s[0] == 't') {
                ok = 0;
                if (!t1) ok = 1;
                if (suf[1][b + 2] || suf[0][b + 2]) ok = 1;
            }
            else {
                ok = 1;
                if (suf[0][b + 2]) ok = 0;
                if (!t1 && suf[1][b + 2]) ok = 0;
            }
        }
        else if (b == n - 1) {
            bool t1 = A[a - 1][0] == 'a';
            if (s[0] == 't') {
                ok = 0;
                if (!t1) ok = 1;
                if (pre[1][a - 2] || pre[0][a - 2]) ok = 1;
            }
            else {
                ok = 1;
                if (pre[0][a - 2]) ok = 0;
                if (!t1 && pre[1][a - 2]) ok = 0;
            }
        }
        else {

            bool t1 = A[a - 1][0] == 'a';
            bool t2 = A[b + 1][0] == 'a';
            if (s[0] == 't') {
                ok = 0;
                if (pre[0][a - 2] || suf[0][b + 2]) ok = 1;
                if (!t1 && !t2) ok = 1;
                if ((!t1 || !t2) && suf[1][b + 2]) ok = 1;
                if ((!t1 || !t2) && pre[1][a - 2]) ok = 1;
                if (pre[1][a - 2] && suf[1][b + 2]) ok = 1;
            }
            else {
                ok = 1;
                if (suf[0][b + 2] || pre[0][a - 2]) ok = 0;
                if (!t1 && pre[1][a - 2]) ok = 0;
                if (!t2 && suf[1][b + 2]) ok = 0;
            }
        }

        ans += (ok ? 'Y' : 'N');

    }
    cout << ans << '\n';


}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}