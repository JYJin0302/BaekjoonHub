#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

ll fastPow(ll b, ll ex, ll mod) {
    ll res = 1;
    while (ex) {
        if (ex & 1) res = res * b % mod;
        ex >>= 1;
        b = b * b % mod;
    }
    return res;
}

char cal(char l, char op, char r) {
    if (l == r) return l;

    if (op == '&') return 'F';
    return 'T';
}
void solve() {

    int n;
    cin >> n;

    vector<char> A(n);
    for (auto& i : A) cin >> i;

    char c;
    cin >> c;

    char cur = A[0];
    for (int i = 2; i < n; i += 2) {
        cur = cal(cur, A[i - 1], A[i]);
    }

    if (c == cur) {
        cout << 0 << '\n';
        return;
    }

    for (int i = 0; i < n; i++) {
        if (i & 1) {
            A[i] = char('|' + '&' - A[i]);
        }
        else {
            A[i] = char('T' + 'F' - A[i]);
        }

        char cur = A[0];
        for (int i = 2; i < n; i += 2) {
            cur = cal(cur, A[i - 1], A[i]);
        }

        if (c == cur) {
            cout << 1 << '\n';
            return;
        }

        if (i & 1) {
            A[i] = char('|' + '&' - A[i]);
        }
        else {
            A[i] = char('T' + 'F' - A[i]);
        }
    }

    cout << 2 << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}