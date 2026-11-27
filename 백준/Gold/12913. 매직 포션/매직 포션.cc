#include <bits/stdc++.h>
using namespace std;
using ll = long long; 
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second


ld dist[55][55];
int c[55][55];

void solve() {

    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char t;
            cin >> t;
            c[i][j] = t - '0';
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) dist[i][j] = -1;
    }

    priority_queue<pair<ld, pair<int, int>>> pq;
    pq.push(mp(0, mp(0, 0)));
    while (!pq.empty()) {
        ld d = pq.top().first;
        auto [a, b] = pq.top().second;
        pq.pop();

        if (dist[b][a] != -1) continue;
        dist[b][a] = -d;

        if (b == 1) {
            cout << -d << '\n';
            return;
        }

        for (int i = 0; i < n; i++) {
            if (dist[i][a] == -1) {
                pq.push(mp(d - c[b][i], mp(a, i)));
            }

            if (a < k && dist[i][a + 1] == -1) {
                pq.push(mp(d - 0.5 * c[b][i], mp(a+1, i)));
            }
        }
    }

    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}