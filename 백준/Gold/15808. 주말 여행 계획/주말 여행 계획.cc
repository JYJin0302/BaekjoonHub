#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int D[1010][1010];

void solve() {

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> D[i][j];
        }
    }

    int a, b;
    cin >> a >> b;
    
    priority_queue<pair<int, int>> pq;
    vector<int> A(n, -1), B(n, -1);
    while (a--) {
        int x, y;
        cin >> x >> y;
        pq.push(mp(y, x - 1));
    }
    while (b--) {
        int x, y;
        cin >> x >> y;
        B[x - 1] = y;
    }

    int ans = -1e9;
    vector<int> dist(n, -1);
    while (!pq.empty()) {

        auto [a, b] = pq.top(); pq.pop();
        if (dist[b] != -1) continue;
        dist[b] = -a;

        if (B[b] != -1) {
            ans = max(ans, B[b] - dist[b]);
        }

        for (int j = 0; j < n; j++) {
            if (D[b][j] && dist[j] == -1) {
                pq.push(mp(a - D[b][j], j));
            }
        }
    }

    cout << ans << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}