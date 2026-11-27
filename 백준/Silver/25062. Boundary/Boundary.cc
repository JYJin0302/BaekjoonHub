#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {

    int a, b;
    cin >> a >> b;

    set<int> ans;

    ans.insert(1);

    int g1 = gcd(a, b - 2);
    for (int i = 1; i * i <= g1; i++) {
        if (g1 % i == 0) {
            ans.insert(i);
            ans.insert(g1 / i);
        }
    }

    g1 = gcd(a - 1, b - 1);
    for (int i = 1; i * i <= g1; i++) {
        if (g1 % i == 0) {
            ans.insert(i);
            ans.insert(g1 / i);
        }
    }

    g1 = gcd(a - 2, b);
    for (int i = 1; i * i <= g1; i++) {
        if (g1 % i == 0) {
            ans.insert(i);
            ans.insert(g1 / i);
        }
    }

    g1 = gcd(a, gcd(a - 2, b - 1));
    for (int i = 1; i * i <= g1; i++) {
        if (g1 % i == 0) {
            ans.insert(i);
            ans.insert(g1 / i);
        }
    }

    g1 = gcd(b, gcd(a - 1, b - 2));
    for (int i = 1; i * i <= g1; i++) {
        if (g1 % i == 0) {
            ans.insert(i);
            ans.insert(g1 / i);
        }
    }

    cout << ans.size() << ' ';
    for (auto f : ans) cout << f << ' ';
    cout << '\n';

}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}