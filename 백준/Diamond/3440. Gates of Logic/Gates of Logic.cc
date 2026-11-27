#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int n, m;
bool tVis[4][222][222];
char G[222][222];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void getInput() {

    memset(G, ' ', sizeof G);
    memset(tVis, 0, sizeof tVis);
    string s;
    getline(cin, s);

    int sn = s.size();
    if (sn != 0 && s[0] == '*') exit(0);
    n = 0, m = 0;
    while (!sn || s[0] != '*') {

        n++;
        m = max(m, sn);
        for (int j = 0; j < sn; j++) {
            G[n][j + 1] = s[j];
        }
        getline(cin, s);
        sn = s.size();
    }

    //cout << "input done\n";
}

bool vis[222][222];
int gDx[222][222];

struct Gate {
    int x1, y1, x2, y2;
    char type;
    int val;
    int inC;

    void pf() {
        cout << x1 << ' ' << y1 << " <-> " << x2 << ' ' << y2 << " | " << type << ' ' << val << '\n';
    }
};

struct Node {
    int x, y, dir;
    int val;
};

void upd(Gate& g, int input) {
    g.inC--;
    if (g.val == -1) {
        g.val = input;
        return;
    }

    if (g.type == '1') {
        g.val |= input;
    }
    else if (g.type == '&') {
        g.val &= input;
    }
    else if (g.type == '=') {
        g.val ^= input;
    }
}

void solve() {

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            vis[i][j] = 0;
            gDx[i][j] = -1;
        }
    }


    vector<pair<int, int>> pos0, pos1;

    queue<Node> q;
    // gate indexing
    vector<Gate> g;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (G[i][j] == '1') {
                q.push({ i, j, 1, 1 });
            }
            else if (G[i][j] == '0') {
                q.push({ i, j, 1, 0 });
            }
            if (G[i][j] != '#' || vis[i][j]) continue;

            int ti = i, tj = j;
            while (G[ti][j] == '#') ti++;
            while (G[i][tj] == '#') tj++;

            char c = '?';
            for (int a = i; a < ti; a++) {
                for (int b = j; b < tj; b++) {
                    vis[a][b] = 1;
                    gDx[a][b] = cnt;
                    if (G[a][b] != ' ' && G[a][b] != '#') c = G[a][b];
                }
            }
            Gate cur = { i, j, ti - 1, tj - 1, c, -1, 0 };

            for (int a = i; a < ti; a++) {
                if (G[a][j - 1] == '=') cur.inC++;
            }

            if (cur.inC == 0) {
                cur.val = 0;
                if (cur.type == '&') cur.val = 1;
                for (int a = i; a < ti; a++) {
                    if (G[a][tj] == '=') {
                        q.push({ a, tj, 1, cur.val });
                    }
                    else if (G[a][tj] == 'o') {
                        q.push({ a, tj, 1, 1 - cur.val });
                    }
                }
            }
            g.push_back(cur);
            cnt++;
        }
    }

    vector<int> res(26, -1);
    while (!q.empty()) {
        Node cur = q.front(); q.pop();
        // cout << "Go: " << cur.x << ' ' << cur.y << " | " << cur.dir << ' ' << cur.val << '\n';

        if (tVis[cur.dir][cur.x][cur.y]) continue;
        tVis[cur.dir][cur.x][cur.y] = 1;

        int nx = cur.x + dx[cur.dir];
        int ny = cur.y + dy[cur.dir];

        char c = G[nx][ny];
        if (c >= 'A' && c <= 'Z') {
            res[c - 'A'] = cur.val;
        }
        else if (c == '#') {
            // gate input
            int gx = gDx[nx][ny];
            upd(g[gx], cur.val);
            if (g[gx].inC == 0) {
                // go output
                int l = g[gx].x1, r = g[gx].x2;
                int w = g[gx].y2;
                for (int ta = l; ta <= r; ta++) {
                    if (G[ta][w + 1] == '=') {
                        q.push({ ta, w + 1, 1, g[gx].val });
                    }
                    else if (G[ta][w + 1] == 'o') {
                        q.push({ ta, w + 1, 1, 1 - g[gx].val });
                    }
                }
            }
        }
        else if (c == 'o') {
            // negation
            q.push({ nx, ny, cur.dir, 1 - cur.val });
        }
        else if (c == '+') {
            for (int i = 0; i < 4; i++) {
                if ((i + 2) % 4 == cur.dir) continue;
                int tx = nx + dx[i];
                int ty = ny + dy[i];

                char tc = G[tx][ty];
                if ((i & 1) && (tc == '-' || tc == '=' || tc == 'x' || tc == '+')) {
                    q.push({ nx, ny, i, cur.val });
                }
                else if (!(i & 1) && (tc == '|' || tc == 'x' || tc == '+')) {
                    q.push({ nx, ny, i, cur.val });
                }
            }
        }
        else {
            // go straight
            q.push({ nx, ny, cur.dir, cur.val });
        }
    }

    for (int i = 0; i < 26; i++) {
        if (res[i] != -1) {
            cout << char('A' + i) << "=" << res[i] << '\n';
        }
    }
    cout << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (1) {
        getInput();
        solve();
    }
}