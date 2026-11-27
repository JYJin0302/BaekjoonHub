#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

#define x first
#define y second

int n, m;

int T[505][505];

pair<int, int> decode(int x){
    return mp(x / m, x % m);
}
int encode(int x, int y) {
    return x * m + y;
}

vector<int> adj[252525];
int topo[252525];

ld A[505][505];
int ans[505][505];

const long double eps = 1e-7;
void solve() {

    cin >> n >> m;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            char c;
            cin >> c;
            T[i][j] = c - '0';
        }
    }

    int mx = m + 1;
    for (int i = 0; i < m; i++) A[0][i] = i + 1;
    for (int i = 1; i < n; i++) {
        vector<pair<ld, ld>> tmp(m);
        tmp[0] = mp(mx + eps, mx + 1 - eps);
        mx += 2;

        for (int j = 1; j < m; j++) {
            int type = T[i][j];
            auto [l, r] = tmp[j - 1];

            ld a = A[i - 1][j - 1];
            ld b = A[i - 1][j];

            if (l < a && a <= r) r = a - eps;
            else if (l <= a && a < r) l = a + eps;

            if (l < b && b <= r) r = b - eps;
            else if (l <= b && b < r) l = b + eps;
            ld c = (l + r) / 2;

            if (a < b && b < c) {
                switch (type) {
                case 1:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                case 2:
                    tmp[j - 1] = mp(r, r);
                    tmp[j] = mp(b + eps, r - eps);
                    break;
                case 3:
                    tmp[j] = mp(a + eps, b - eps);
                    break;
                }
            }
            else if (a < c && c < b) {
                switch (type) {
                case 1:
                    tmp[j - 1] = mp(r, r);
                    tmp[j] = mp(a + eps, r - eps);
                    break;
                case 2:
                    tmp[j - 1] = mp(l, l);
                    tmp[j] = mp(l + eps, b - eps);
                    break;
                case 3:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                }
            }
            else if (b < a && a < c) {
                switch (type) {
                case 1:
                    tmp[j - 1] = mp(r, r);
                    tmp[j] = mp(a + eps, r - eps);
                    break;
                case 2:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                case 3:
                    tmp[j] = mp(b + eps, a - eps);
                    break;
                }
            }
            else if (c < a && a < b) {
                switch (type) {
                case 1:
                    tmp[j - 1] = mp(l, l);
                    tmp[j] = mp(l + eps, a - eps);
                    break;
                case 2:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                case 3:
                    tmp[j] = mp(a + eps, b - eps);
                    break;
                }
            }
            else if (b < c && c < a) {
                switch (type) {
                case 1:
                    tmp[j - 1] = mp(l, l);
                    tmp[j] = mp(l + eps, a - eps);
                    break;
                case 2:
                    tmp[j - 1] = mp(r, r);
                    tmp[j] = mp(b + eps, r - eps);
                    break;
                case 3:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                }
            }
            else if (c < b && b < a) {
                switch (type) {
                case 1:
                    tmp[j] = mp(mx + eps, mx + 1 - eps);
                    mx += 2;
                    break;
                case 2:
                    tmp[j - 1] = mp(l, l);
                    tmp[j] = mp(l + eps, b - eps);
                    break;
                case 3:
                    tmp[j] = mp(b + eps, a - eps);
                    break;
                }
            }
            else {
                assert(0);
            }

        }

        for (int j = 0; j < m; j++) {
            A[i][j] = tmp[j].x;
        }

        //cout << "STate: \n";
        //for (int j = 0; j < m; j++) cout << A[i - 1][j] << ' ';
        //cout << '\n';
        //for (int j = 0; j < m; j++) cout << A[i][j] << ' ';
        //cout << '\n';

        for (int j = 1; j < m; j++) {
            vector<pair<int, int>> pos = { mp(i - 1, j - 1), mp(i - 1, j) ,mp(i, j - 1), mp(i, j) };

            for (int a = 0; a < 4; a++) {
                for (int b = a + 1; b < 4; b++) {
                    ld v1 = A[pos[a].x][pos[a].y];
                    ld v2 = A[pos[b].x][pos[b].y];
                    if (v1 < v2) {
                        adj[encode(pos[a].x, pos[a].y)].push_back(encode(pos[b].x, pos[b].y));
                        topo[encode(pos[b].x, pos[b].y)]++;
                    }
                    else {
                        adj[encode(pos[b].x, pos[b].y)].push_back(encode(pos[a].x, pos[a].y));
                        topo[encode(pos[a].x, pos[a].y)]++;
                    }
                }
            }
        }

        vector<pair<ld, int>> tt;
        for (int j = 0; j < m; j++) tt.push_back(mp(A[i][j], j));
        sort(all(tt));

        for (int j = 0; j < m; j++) {
            A[i][tt[j].y] = j;
        }
    }

    queue<int> q;
    for (int i = 0; i < n * m; i++) {
        if (topo[i] == 0) q.push(i);
    }

    int num = 1;
    while (!q.empty()) {
        auto v = q.front(); q.pop();

        auto [a, b] = decode(v);
        ans[a][b] = num++;

        for (auto f : adj[v]) {
            topo[f]--;
            if (topo[f] == 0) q.push(f);
        }
    }

    assert(num == n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }
    

}
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << setprecision(10);

    solve();
    return 0;
}