#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m, k;
int dist[1 << 10][55][55];
vector<int> mosList[55][55];

int dx[] = { -1, 0, 1,  0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 1 && x <= n&& y >= 1 && y <= m;
}
void setM(int& msk, int pos) {
    if (msk & (1 << pos)) {}
    else msk += 1 << pos;
}
int bCnt(int msk) {
    int res = 0;
    for (int i = 0; i < k; i++) {
        if (msk & (1 << i)) res++;
    }
    return res;
}
void solve() {

    cin >> n >> m >> k;

    int t, p;
    cin >> t >> p;

    vector<pair<pair<int, int>, int>> mos;
    for(int i = 0; i < k; i++){
        int a, b, h;
        cin >> a >> b >> h;
        mos.push_back(mp(mp(a, b), h));
        mosList[a][b].push_back(i);
    }

    memset(dist, -1, sizeof(dist));

    queue<pair<pair<int, int>, int>> q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int msk = 0;
            for (auto f : mosList[i][j])setM(msk, f);

            dist[msk][i][j] = 0;
            q.push(mp(mp(i, j), msk));
        }
    }

    int ans1 = 0, ans2 = 0;
    while (!q.empty()) {

        auto [a, b] = q.front().x;
        int msk = q.front().y;
        q.pop();

        ans1 = max(ans1, bCnt(msk));
        if (dist[msk][a][b] == t) continue;

        for (int i = 0; i < 4; i++) {
            int na = a + dx[i];
            int nb = b + dy[i];

            if (inGrid(na, nb)) {
                int nmsk = msk;
                for (auto f : mosList[na][nb]) setM(nmsk, f);

                if (dist[nmsk][na][nb] == -1) {
                    dist[nmsk][na][nb] = dist[msk][a][b] + 1;
                    q.push(mp(mp(na, nb), nmsk));
                }
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int res = 0;

            for (int f = 0; f < k; f++) {

                int a, b;
                tie(a, b) = mos[f].x;
                int h = mos[f].y;

                int d = abs(a - i) + abs(b - j);

                if (d == 0 || p / d >= h) res++;

            }
            ans2 = max(ans2, res);
        }
    }

    cout << ans1 << ' ' << ans2;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}