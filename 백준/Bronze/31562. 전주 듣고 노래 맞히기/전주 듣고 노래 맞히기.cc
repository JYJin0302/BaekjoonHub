#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

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

map<string, string> nm;
map<string, int> cnt;
void solve() {

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        string s;
        cin >> s;

        string res;
        for (int j = 0; j < 7; j++) {
            char c;
            cin >> c;
            if (j < 3) res += c;
        }

        cnt[res]++;
        nm[res] = s;
    }

    while (m--) {
        string res(3, '_');
        for (int i = 0; i < 3; i++) {
            cin >> res[i];
        }

        if (cnt[res] >= 2) cout << "?\n";
        else if (cnt[res] == 0) cout << "!\n";
        else cout << nm[res] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}