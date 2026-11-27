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


void solve() {

    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        int cc = 0, cC = 0, cd = 0;
        for (auto f : s) {
            if (f >= 'a' && f <= 'z') cc++;
            else if (f >= 'A' && f <= 'Z') cC++;
            else if (f != '-') cd++;
        }

        bool ok = 1;
        if (cd == s.size()) ok = 0;
        if (cc < cC) ok = 0;
        if (s.size() > 10) ok = 0;

        if (ok) {
            cout << s << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}