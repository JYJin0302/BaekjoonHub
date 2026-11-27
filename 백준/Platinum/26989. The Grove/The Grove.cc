#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
string G[55];
int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1 };
int dy[] = { 0, 1, 0, -1 , -1, 1, -1, 1};
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

int dist[1 << 4][55][55];

void setM(int& msk, int pos) {
    if (msk & (1 << pos)) {}
    else msk += 1 << pos;
}

string pf(int msk) {
    string res;
    for (int i = 0; i < 4; i++) {
        if (msk & (1 << i)) res += '1';
        else res += '0';
    }
    return res;
}

void solve() {

    memset(dist, -1, sizeof(dist));
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> G[i];
    }

    int sx = -1, sy = -1;
    vector<pair<int, int>> p(4, mp(-1, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (G[i][j] == '*') {
                sx = i, sy = j;
            }
            else if (G[i][j] == 'X') {
                if (p[0] == mp(-1, -1)) {
                    p = vector<pair<int, int>>(4, mp(i, j));
                }
                else {
                    p[0] = min(p[0], mp(i, j));
                    p[1] = max(p[1], mp(i, j));
                    if (j < p[2].y) p[2] = mp(i, j);
                    if (j > p[3].y) p[3] = mp(i, j);
                }
            }
        }
    }

    queue<pair<pair<int, int>, int>> q;
    q.push(mp(mp(sx, sy), 0));
    dist[0][sx][sy] = 0;

    while (!q.empty()) {

        int a, b;
        tie(a, b) = q.front().x;
        int msk = q.front().y;
        q.pop();
        for (int i = 0; i < 8; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];
            if (inGrid(na, nb) && G[na][nb] != 'X') {
                int nmsk = msk;
                if (na <= p[0].x && nb == p[0].y) setM(nmsk, 0);
                else if (na >= p[1].x && nb == p[1].y) setM(nmsk, 1);
                else if (na == p[2].x && nb <= p[2].y) setM(nmsk, 2);
                else if (na == p[3].x && nb >= p[3].y) setM(nmsk, 3);

                if (dist[nmsk][na][nb] == -1) {
                    dist[nmsk][na][nb] = dist[msk][a][b] + 1;
                    q.push(mp(mp(na, nb), nmsk));
                }
            }
        }
    }

    cout << dist[15][sx][sy];

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}