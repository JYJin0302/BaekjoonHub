#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int S[333][333];
bool vis[333][333];
const int INF = 0x3f3f3f3f;
bool inGrid(int x, int y) {
    return x >= 0 && x < 330&& y >= 0 && y < 330;
}
void solve() {


    memset(S, INF, sizeof S);


    int n;
    cin >> n;

    while (n--) {
        int a, b, t;
        cin >> a >> b >> t;

        S[a][b] = min(S[a][b], t);
        for (int i = 0; i < 4; i++) {
            int nx = a + dx[i];
            int ny = b + dy[i];

            if (inGrid(nx, ny)) S[nx][ny] = min(S[nx][ny], t);
        }

    }

    int d = 0;
    queue<pair<int, int>> q, tq;
    q.push(mp(0, 0));
    vis[0][0] = 1;
    while (!q.empty()) {

        while (!q.empty()) {
            auto [a, b] = q.front(); q.pop();
            if (S[a][b] == INF) {
                cout << d;
                return;
            }

            for (int j = 0; j < 4; j++) {
                int na = a + dx[j];
                int nb = b + dy[j];
                if (inGrid(na, nb) && !vis[na][nb] && S[na][nb] > d + 1) {
                    vis[na][nb] = 1;
                    tq.push(mp(na, nb));
                }
            }
        }

        d++;
        swap(q, tq);
    }
    cout << -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}