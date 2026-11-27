#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

bool isConn(pair<int, int> p1, pair<int, int> p2) {
    int dx = abs(p1.x - p2.x);
    int dy = abs(p1.y - p2.y);
    return !dx || !dy || dx == dy;
}

void solve() {

    int n;
    cin >> n;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;

    int ix = -1;
    for (int i = 1; i < n; i++) {
        if (!isConn(A[0], A[i])) ix = i;
    }

    if (ix == -1) {
        cout << "YES\n";
        cout << A[0].x << ' ' << A[0].y << '\n';
        return;
    }
    auto [a, b] = A[0];
    auto [c, d] = A[ix];
    if (a > c) {
        swap(a, c);
        swap(b, d);
    }

    vector<pair<int, int>> B;
    B.push_back(mp(a, d));
    B.push_back(mp(c, b));

    B.push_back(mp(a, d + abs(c - a)));
    B.push_back(mp(a, d - abs(c - a)));
    B.push_back(mp(c, b + abs(c - a)));
    B.push_back(mp(c, b - abs(c - a)));

    B.push_back(mp(a + abs(d - b), d));
    B.push_back(mp(a - abs(d - b), d));
    B.push_back(mp(c - abs(d - b), b));
    B.push_back(mp(c + abs(d - b), b));

    int v = -a + b + c - d;
    if (v % 2 == 0) {
        B.push_back(mp(c - v / 2, d + v / 2));
        B.push_back(mp(a + v / 2, b - v / 2));
    }

    for (auto f : B) {
        bool ok = 1;
        for (int i = 0; i < n; i++) {
            if (!isConn(f, A[i])) ok = 0;
        }
        if (ok) {
            cout << "YES\n" << f.x << ' ' << f.y << '\n';
            return;
        }
    }

    cout << "NO\n";
    

}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}