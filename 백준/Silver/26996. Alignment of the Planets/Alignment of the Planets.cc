#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int ccw(pair<int, int>& a, pair<int, int>& b, pair<int, int>& c) {
    int res = a.x * b.y + b.x * c.y + c.x * a.y;
    res -= a.y * b.x + b.y * c.x + c.y * a.x;
    return res;
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    vector<pair<int, pair<int, int>>> ans;
    for (auto& i : A) cin >> i.x >> i.y;
    for (int a = 0; a < n; a++) {
        for (int b = a + 1; b < n; b++) {
            for (int c = b + 1; c < n; c++) {
                if (ccw(A[a], A[b], A[c]) == 0) ans.push_back(mp(a, mp(b, c)));
            }
        }
    }

    cout << ans.size() << '\n';
    for (auto& f : ans) {
        cout << f.x + 1 << ' ' << f.y.x + 1 << ' ' << f.y.y + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}