#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define x first
#define y second

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };

int n, m, q;
int A[501][501];

vector<int> root;
int find(int t) {
    if (root[t] == t) return t;
    return root[t] = find(root[t]);
}

bool inGrid(int t, int t2) {
    return t >= 0 && t < n&& t2 >= 0 && t2 < m;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> A[i][j];
        }
    }

    vector<pair<int, int>> route(q);
    for (int i = 0; i < q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        route[i] = { a * m + b, c * m + d };
    }
    
    vector<tuple<int, int, int>> conn;
    conn.push_back({ 1, 0, 0 });

    for (int i = 0; i < n * m; i++) {

        int ix = i / m, iy = i%m;
        for (int j = 0; j < 4; j++) {
            int nx = ix + dx[j];
            int ny = iy + dy[j];

            if (inGrid(nx, ny) && A[nx][ny] <= A[ix][iy]) {
                conn.push_back({ A[ix][iy], i, nx* m + ny });
            }
        }
    }
    sort(conn.begin(), conn.end());
    conn.push_back({ 1e6 + 1, 0, 0});


    vector<int> res(q);
    vector<pair<int, int>> ans(q);
    for (int i = 0; i < q; i++) {
        ans[i] = { 1, 1e6 };
        if (route[i].x == route[i].y) {
            ans[i] = { 0, -1 };
            int ti = route[i].x / m, tj = route[i].y % m;
            res[i] = A[ti][tj];
        }
    }

    while (1) {

        bool is = 0;

        vector<vector<int>> md(1e6 + 1);
        for (int i = 0; i < q; i++) {
            if (ans[i].y >= ans[i].x) {
                is = 1;
                md[(ans[i].y + ans[i].x) / 2].push_back(i);
            }
        }
        
        if (!is) break;

        root = vector<int>(n*m);
        for (int i = 0; i < n * m; i++) root[i] = i;

        int pv = 0;
        for (auto i : conn) {

            int d, a, b;
            tie(d, a, b) = i;

            if (d != pv) {
                for (int j = pv; j < d; j++) {
                    for (int k : md[j]) {
                        // check route k is connected
                        int s = route[k].x, e = route[k].y;

                        s = find(s), e = find(e);
                        if (s == e) {
                            res[k] = pv;
                            ans[k].y =pv - 1;
                        }
                        else ans[k].x = d;
                    }
                }
                pv = d;
            }
            

            int ta = find(a), tb = find(b);
            if (ta != tb) {
                root[ta] = tb;
            }
        }
    }

    for (auto i : res) {
        cout << i << '\n';
    }
}