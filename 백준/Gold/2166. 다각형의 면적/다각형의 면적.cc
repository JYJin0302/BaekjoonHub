#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, a, b, c, d, x, y, x1, x2, y1, y2;
    cin >> n;
    vector<pair<ll, ll>> A;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        A.push_back({ a, b });
    }
    double ans = 0;
    tie(a, b) = A[0];
    tie(c, d) = A[1];
    for (int i = 2; i < n; i++) {
        tie(x, y) = A[i];
        x1 = x - a;
        x2 = c - a;
        y1 = y - b;
        y2 = d - b;

        ans += x1 * y2 - x2 * y1;
        tie(c, d) = A[i];
    }
    cout << fixed;
    cout.precision(1);
    cout << abs(ans) / 2;
}