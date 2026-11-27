#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define x first
#define y second
#define mp make_pair
#define all(x) x.begin(), x.end()

#define yes {cout << "yes\n"; return;}

ll gcd(ll a, ll b) {
    if (a > b) swap(a, b);
    if (a == 0) return b;
    return gcd(b % a, a);
}

pair<int, int> getMatch(string s1, string s2) {
    int n = s1.size(), m = s2.size();

    vector<int> fail(n);
    int j = 0;
    for (int i = 1; i < n; i++) {
        while (j && s1[i] != s1[j]) j = fail[j - 1];
        if (s1[i] == s1[j]) j++;
        fail[i] = j;
    }

    vector<int> res;
    j = 0;
    for (int i = 0; i < m; i++) {
        while (j && s1[j] != s2[i]) j = fail[j - 1];

        if (s2[i] == s1[j]) {
            j++;
            if (j == n) {
                res.push_back(i - n + 1);
                j = fail[j - 1];
            }
        }
    }

    if (res.empty()) return mp(-1, -1);
    int len = n;
    if (res.size() >= 2) {
        len = res[1] - res[0];
        for (int i = 1; i < res.size(); i++) {
            assert(res[i] - res[i - 1] == len);
        }
    }


    return mp(len, res[0]);
}

int n, m;
int G[505][505], R[505][505];
int A[505][505], B[505][505];
bool inGrid(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}


void setG() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            A[i][j] = G[i][j];
        }
    }
}

void setA() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            B[i][j] = A[i][j];
        }
    }
}

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


void pf(int grid[][505]) {
    cout << string(m + 10, '-') << '\n';
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (grid[i][j]) cout << char('a' + grid[i][j] - 1);
            else cout << '.';
        }
        cout << '\n';
    }
    cout << string(m + 10, '-') << '\n';
}

void tilt(int dir, int grid[][505]) {
    switch (dir) {
    case 0:
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j]) {
                    int val = grid[i][j];
                    grid[i][j] = 0;
                    int ni = i - 1;
                    while (ni >= 1 && grid[ni][j] == 0) ni--;
                    grid[ni + 1][j] = val;
                }
            }
        }
        break;
    case 1:
        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (grid[i][j]) {
                    int val = grid[i][j];
                    grid[i][j] = 0;
                    int nj = j + 1;
                    while (nj <= m && grid[i][nj] == 0) nj++;
                    grid[i][nj - 1] = val;
                }
            }
        }
        break;
    case 2:
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j]) {
                    int val = grid[i][j];
                    grid[i][j] = 0;
                    int ni = i + 1;
                    while (ni <= n && grid[ni][j] == 0) ni++;
                    grid[ni - 1][j] = val;
                }
            }
        }

        break;
    case 3:
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (grid[i][j]) {
                    int val = grid[i][j];
                    grid[i][j] = 0;
                    int nj = j - 1;
                    while (nj >= 1 && grid[i][nj] == 0) nj--;
                    grid[i][nj + 1] = val;
                }
            }
        }
        break;
    default:
        return;
    }
}

bool vis[505][505];
void goSolve() {

    tilt(0, A);
    tilt(1, A);
    setA();
    //pf(A);
    bool ok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if ((A[i][j] >= 1) ^ (R[i][j] >= 1)) {
                return;
            }
            if (A[i][j]) A[i][j] = (i - 1) * m + j;
            vis[i][j] = 0;
        }
    }

    for (int f = 3; f >= 0; f--) {
        tilt(f, A);
    }

    vector<pair<string, string>> match;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] || A[i][j] == 0) continue;


            vector<pair<int, int>> route;
            int ni = i, nj = j;
            while (!vis[ni][nj]) {
                vis[ni][nj] = 1;
                route.push_back(mp(ni, nj));

                int val = A[ni][nj] - 1;
                int ti = val / m + 1;
                int tj = val % m + 1;
                ni = ti, nj = tj;
            }

            reverse(all(route));

            /*cout << "Route found: ";
            for (auto [a, b] : route) cout << a << ' ' << b << " | ";
            cout << '\n';*/

            string s1, s2;
            for (auto [a, b] : route) {
                s1 += char('a' + B[a][b] - 1);
                s2 += char('a' + R[a][b] - 1);
            }
            match.push_back(mp(s1, s2));
            //cout << s1 << ' ' << s2 << '\n';
        }
    }

    // matching with kmp
    vector<pair<int, int>> res; // {a, b} : x % a = b;
    for (auto [s1, s2] : match) {
        auto [a, b] = getMatch(s1, s2 + s2);
        if (a == -1) return;
        res.push_back(mp(a, b));

        // cout << s1 << ' ' << s2 << " => " << a << ' ' << b << '\n';
    }

    sort(all(res));
    res.erase(unique(all(res)), res.end());

    int sn = res.size();

    for (int i = 0; i < sn; i++) {
        for (int j = i + 1; j < sn; j++) {
            if (res[i].x == res[j].x) return;
            int g = gcd(res[i].x, res[j].x);

            if (abs(res[i].y - res[j].y) % g == 0) continue;
            return;
        }
    }

    cout << "yes\n";
    exit(0);
}

void solve() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') G[i][j] = 0;
            else G[i][j] = c - 'a' + 1;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') R[i][j] = 0;
            else R[i][j] = c - 'a' + 1;
        }
    }

    bool tok = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (R[i][j] != G[i][j]) tok = 0;
        }
    }
    if (tok) yes;

    // try one move
    for (int f = 0; f < 4; f++) {
        setG();
        tilt(f, A);
        tok = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (R[i][j] != A[i][j]) tok = 0;
            }
        }
        if (tok) yes;
    }

    // check ansgrid is cornered
    vector<bool> chk(4, 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!R[i][j]) continue;
            for (int f = 0; f < 4; f++) {
                int ni = i + dx[f];
                int nj = j + dy[f];
                if (inGrid(ni, nj) && R[ni][nj] == 0) chk[f] = 0;
            }
        }
    }
    if (!chk[0] && !chk[2]) {
        cout << "no\n";
        return;
    }

    if (!chk[1] && !chk[3]) {
        cout << "no\n";
        return;
    }

    // set ans grid
    tilt(0, R);
    tilt(1, R);

    // check two initial state
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            setG();
            tilt(i, A);
            tilt(j, A);
            //cout << "Go: " << ss[i] << ss[j] << '\n';
            goSolve();
        }
    }

    cout << "no\n";

}


int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}