#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

// 4 * 1024 * 1024
const int MAXN = 1 << 22;

int n, m, x, y, d;
int A[1030][1030], B[1030][1030];
bool isDust[1030][1030];
int len[MAXN];
int nxt[MAXN];


int getNext(int x) {
    if (nxt[x] == x || nxt[x] == -1) return x;
    int nx = getNext(nxt[x]);
    len[x] += len[nxt[x]];
    nxt[x] = nx;
    return nx;
}

int getVal(int d, int x, int y) {
    int res = d;
    res = (res << 10) + x;
    res = (res << 10) + y;
    return res;
}

void setVal(int val) {
    y = val % (1 << 10);
    val >>= 10;
    x = val % (1 << 10);
    val >>= 10;
    d = val;
}

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}



void solve() {

    memset(nxt, -1, sizeof(nxt));

    cin >> n >> m;
    cin >> x >> y >> d;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            A[i][j] = c - '0';
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            B[i][j] = c - '0';
        }
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) isDust[i][j] = 1;

    ll ans = 0, tmp = 0;
    while (inGrid(x, y)) {
        bool chk = isDust[x][y];
        int val = getVal(d, x, y);

      // cout << "curr: "<< d << ' ' << x << ' ' << y << '\n';
        if (!chk) {
            if (nxt[val] == -1) {
                //cout << "Conn: " << d << ' ' << x << ' ' << y << " -> ";
                d = (d + B[x][y]) % 4;
                x += dx[d];
                y += dy[d];
              //  cout << d << ' ' << x << ' ' << y << "\n";

                if (!inGrid(x, y)) break;

                int nx = getVal(d, x, y);
                int tt = getNext(nx);
                if (tt == val) {
                    // cycle
                    break;
                }
                nxt[val] = nx;
                len[val] = 1;
            }
            int nx = getNext(val);
            tmp += len[val];
            setVal(nx);
            continue;
        }

        isDust[x][y] = 0;
        ans += tmp;
        tmp = 1;

        d = (d + A[x][y]) % 4;
        x += dx[d];
        y += dy[d];
    }

    cout << ans + 1 << '\n';

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
}