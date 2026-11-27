#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dist[303][303];

void solve() {

    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> A;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                if (dist[j][k] > dist[j][i] + dist[i][k]) {
                    cout << -1;
                    return;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            bool ok = 1;
            for (int k = 0; k < n; k++) {
                if (i == k || k == j) continue;
                if (dist[i][j] == dist[i][k] + dist[k][j]) {
                    ok = 0;
                    break;
                }
            }

            if (ok && i < j) A.push_back(mp(dist[i][j], mp(i, j)));
        }
    }

    cout << A.size() << '\n';
    for (auto [a, b] : A) {
        cout << b.x + 1 << ' ' << b.y + 1 << ' ' << a << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);


    int t = 1;
    // cin >> t;
    while (t--) solve();
}