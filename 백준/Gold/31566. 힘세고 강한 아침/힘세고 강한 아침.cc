#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

const int INF = 3e8;

int dist[101][101];
int tmp[101][101];

vector<pair<pair<int, int>, int>> qur[101];

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dist[i][j] = INF;
        }
    }

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        dist[a][b] = c;
    }

    for (int i = 0; i < q; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--, c--;
        qur[b].push_back(mp(mp(a, c), i));
    }

    vector<int> ans(q);
    for(int b = 0; b < n; b++){
        if (qur[b].empty()) continue;

        for (register int i = 0; i < n; i++) {
            for (register int j = 0; j < n; j++) {
                tmp[i][j] = dist[i][j];
            }
        }

        for (register int i = 0; i < n; i++) {
            if (i == b) continue;
            for (register int j = 0; j < n; j++) {
                if (j == b) continue;
                for (register int k = 0; k < n; k++) {
                    if (k == b) continue;
                    tmp[j][k] = min(tmp[j][k], tmp[j][i] + tmp[i][k]);
                }
            }
        }

        for(auto& f : qur[b]){
            auto& [x, y] = f.first;
            int idx = f.second;
            ans[idx] = tmp[x][y];
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i] == INF) cout << "No\n";
        else cout << ans[i] << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}