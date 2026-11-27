#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second



void solve() {

    int n, m;
    cin >> n >> m;

    vector<int> A(m);
    for (auto& i : A) cin >> i;

    vector<bool> used(n + 1);

    int cur = n;
    int sz = n, ix = 0;
    while (sz > 1) {
        int v = A[ix] % sz;
        if (v == 0) v = sz;
        while (v--) {
            cur = cur % n + 1;
            if (used[cur]) v++;
        }
        ix = (ix + 1) % m;
        used[cur] = 1;
        sz--;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) cout << i;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}