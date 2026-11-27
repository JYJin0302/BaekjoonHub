#include <bits/stdc++.h>
using namespace std;
#define mp make_pair

int n;
string A[1010];
int mdist[1010][1010];

int root[1010101];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < n;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    memset(mdist, -1, sizeof(mdist));
    // 중심 i, j :  정사각형 길이 홀수만 가능

    queue<pair<int, int>> que;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] == '.') {
                bool ok = 0;
                if (i == 0 || i == n - 1) ok = 1;
                if (j == 0 || j == n - 1) ok = 1;

                for (int dx = -1; dx <= 1; dx++) {
                    for (int dy = -1; dy <= 1; dy++) {
                        if (inGrid(i + dx, j + dy) && A[i + dx][j + dy] == '#') ok = 1;
                    }
                }

                if (ok) {
                    que.push({ i, j });
                    mdist[i][j] = 1;
                }
            }
            else mdist[i][j] = 0;
        }
    }

    int mx = 1;
    while (!que.empty()) {

        int a, b;
        tie(a, b) = que.front();
        que.pop();
        mx = max(mx, mdist[a][b]);
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {

                if (inGrid(a + dx, b + dy) && mdist[a + dx][b + dy] == -1) {
                    mdist[a + dx][b + dy] = mdist[a][b] + 1;
                    que.push({ a + dx, b + dy });
                }
            }
        }
    }
    /*for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << mdist[i][j];
        }
        cout << '\n';
    }*/

    vector<pair<int, int>> query;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--, y1--, x2--, y2--;

        query.push_back({ x1 * n + y1, x2 * n + y2 });
    }

    vector<pair<int, pair<int, int>>> edge;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mdist[i][j] != 0 && j + 1 < n && mdist[i][j + 1] != 0) {
                edge.push_back(mp(min(mdist[i][j], mdist[i][j + 1]), mp(i * n + j, i * n + j + 1)));
            }
            if (mdist[i][j] != 0 && i + 1 < n && mdist[i + 1][j] != 0) {
                edge.push_back(mp(min(mdist[i][j], mdist[i + 1][j]), mp((i + 1) * n + j, i * n + j)));
            }
        }
    }
    sort(edge.rbegin(), edge.rend());

    vector<int> ans(q);
    vector<pair<int, int>> md(q, make_pair(1, mx));

    while (1) {
        bool ck = 0;
        vector<vector<int>> qList(mx + 1);

        for (int i = 0; i < q; i++) {
            if (md[i].first <= md[i].second) {
                ck = 1;
                qList[(md[i].first + md[i].second) / 2].push_back(i);
            }
        }

        if (!ck) break;
        for (int i = 0; i < n * n; i++) {
            root[i] = i;
        }

        int ix = 0;
        while (ix < edge.size()) {
            int curr = edge[ix].first;
            while (ix < edge.size() && edge[ix].first == curr) {
                int u = edge[ix].second.first, v = edge[ix].second.second;
                int tu = u, tv = v;
                u = find(u), v = find(v);
                ix++;

                if (u != v) {
                    root[u] = v;
                }
            }

            for (auto idx : qList[curr]) {
                if (find(query[idx].first) == find(query[idx].second)) {
                    ans[idx] = curr;
                    md[idx].first = curr + 1;
                }
                else {
                    md[idx].second = curr - 1;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i] == 0) cout << "0\n";
        else cout << ans[i] * 2 - 1 << '\n';
    }
}