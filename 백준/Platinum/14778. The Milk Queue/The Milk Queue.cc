#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

bool cmp(pair<int, int>& p1, pair<int, int>& p2) {
    int v1 = (p1.x < p1.y) ? p1.x : 1e9 - p1.y;
    int v2 = (p2.x < p2.y) ? p2.x : 1e9 - p2.y;
    return v1 < v2;
}

void solve() {

    int n;
    cin >> n;

    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.x >> i.y;
    sort(all(A), cmp);

    ll l = 0, r = 0;
    for (auto& [a, b] : A) {
        l += a;
        r = max(l, r) + b;
    }
    cout << r << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}