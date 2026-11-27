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

    int n; cin >> n;

    string s2;
    vector<pair<string, string>> A(n+1);
    for (auto& i : A) {
        cin >> i.x >> i.y;
        if (i.y == "teacher") s2 = i.x;
    }

    string ts;
    cin >> ts;

    int cnt = 0;
    for (auto [a, b] : A) {
        if (b == "teacher") continue;
        if (a < s2 || a < ts) {}
        else cnt++;
    }

    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}