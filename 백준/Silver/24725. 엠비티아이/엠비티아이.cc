#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define all(x) x.begin(), x.end()
#define mp make_pair

int n, m;
char G[202][202];
int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}

bool chk[4][26];

void solve() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> G[i][j];
        }
    }

    chk[0]['E' - 'A'] = 1;
    chk[0]['I' - 'A'] = 1;

    chk[1]['N' - 'A'] = 1;
    chk[1]['S' - 'A'] = 1;

    chk[2]['F' - 'A'] = 1;
    chk[2]['T' - 'A'] = 1;

    chk[3]['P' - 'A'] = 1;
    chk[3]['J' - 'A'] = 1;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int d = 0; d < 8; d++) {

                int cur = 0;
                int cx = i, cy = j;
                while (inGrid(cx, cy) && cur < 4) {
                    if (chk[cur][G[cx][cy] - 'A']) {
                        cur++;
                        cx += dx[d];
                        cy += dy[d];
                    }
                    else break;
                }

                if (cur == 4) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';


}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

    return 0;
}