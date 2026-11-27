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


bool cmp(string s1, string s2) {

    int c1 = 0;
    for (auto f : s1) c1 += (f == '1');
    int c2 = 0;
    for (auto f : s2) c2 += (f == '1');

    if (c1 != c2) return c1 < c2;
    reverse(all(s1));
    reverse(all(s2));
    return s1 < s2;
}
void solve() {

    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<string> A;
    for (int i = 0; i < (1 << n); i++) {
        string ts;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) ts += '1';
            else ts += '0';
        }
        A.push_back(ts);
    }
    sort(all(A), cmp);

    for (int i = 0; i < A.size(); i++) {
        if (A[i] == s) cout << i << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}