#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<bool> c1(n + 1);
    while (k--) {
        int x;
        cin >> x;
        c1[x] = 1;
    }

    vector<pair<int, pair<int, int>>> A(m);
    for (int i = 0; i < m; i++) {
        int t, a, b;
        cin >> t >> a >> b;
        A[i] = mp(t, mp(a, b));
    }

    sort(all(A));

    for (int i = 1; i <= n; i++) {
        if (!c1[i]) continue;
        vector<bool> co(n + 1);
        co[i] = 1;
        
        for (auto& [a, b] : A) {
            if (co[b.x]) co[b.y] = 1;
        }

        bool ok = 1;
        for (int j = 1; j <= n; j++) {
            if (co[j] != c1[j]) ok = 0;
        }
        if (ok) {
            cout << i << '\n';
            return;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}