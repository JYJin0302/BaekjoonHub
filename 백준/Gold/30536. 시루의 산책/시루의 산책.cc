#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int dist2(pair<int, int>& p1, pair<int, int>& p2) {
    return (p1.x - p2.x)* (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

void solve() {

    int n, m; cin >> n >> m;
    vector<pair<int, int>> A(n);
    for (auto& i : A) cin >> i.first >> i.second;

    vector<pair<int, int>> pos(m);
    for (auto& i : pos) cin >> i.first;

    int r;
    cin >> r;
    for (auto& i : pos) cin >> i.second;

    int ans = 0;
    queue<int> q;
    vector<bool> inQ(n);

    for (int i = 0; i < n; i++) {
        bool ok = 1;
        for (int j = 0; j < m; j++) {
            if (dist2(A[i], A[pos[j].first - 1]) <= pos[j].second * pos[j].second) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            inQ[i] = 1;
            q.push(i);
        }
    }

    while (!q.empty()) {
        int a = q.front(); q.pop();
        ans++;
        for (int i = 0; i < n; i++) {
            if (!inQ[i] && dist2(A[i], A[a]) <= r * r) {
                inQ[i] = 1;
                q.push(i);
            }
        }
    }
    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
   // cin >> t;
    while (t--) solve();
}