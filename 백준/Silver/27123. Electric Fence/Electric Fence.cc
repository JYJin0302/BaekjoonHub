#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int gcd(int a, int b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

void solve() {


    int n, m, p;
    cin >> n >> m >> p;

    int a = m * p;
    int c = p;
    c += gcd(n, m);
    c += gcd(abs(n - p), m);
    cout << (a - (c-2)) / 2 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}