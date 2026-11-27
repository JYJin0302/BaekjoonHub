#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int root[1010];
int find(int n) {
    if (root[n] == n)return n;
    return root[n] = find(root[n]);
}

void solve() {

    int n, m;
    cin >> n >> m;

    while (n + m) {
        for (int i = 1; i <= n; i++) root[i] = i;

        vector<pair<int, pair<int, int>>> A;
        while (m--) {
            int a, b, c;
            cin >> a >> b >> c;
            A.push_back(mp(c, mp(a, b)));
        }
        sort(all(A));

        vector<int> res;
        for (auto f : A) {
            auto [a, b] = f.y;
            a = find(a), b = find(b);
            if (a == b) continue;
            res.push_back(f.x);
            root[b] = a;
        }

        cout << res[n / 2 - 1] << '\n';
        cin >> n >> m;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}