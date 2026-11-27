#include <bits/stdc++.h>
using namespace std;

int n, m;
int carcnt = 0, parkcnt = 0;
vector<string> grid;
int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };
map<pair<int, int>, int> ptoci, ptopi;  // pair -> car index, pair -> park index
map<int, pair<int, int>> citop, pitop;

vector < vector<pair<int, int>>> adj;

bool inGrid(int x, int y) {
    return x >= 0 && x < n&& y >= 0 && y < m;
}
void bfs(int x, int y, int ind) {
    vector<vector<bool>> visit(n, vector<bool>(m));
    queue<tuple<int, int, int>> q;
    q.push({ 0, x, y });
    visit[x][y] = 1;
    while (!q.empty()) {

        int a, b, c;
        tie(a, b, c) = q.front();
        q.pop();
        if (grid[b][c] == 'P') {
            int k = ptopi[{b, c}];
            adj[ind].push_back({ k, a });
        }

        for (int i = 0; i < 4; i++) {
            int nb = b + dx[i];
            int nc = c + dy[i];

            if (inGrid(nb, nc) && !visit[nb][nc] && grid[nb][nc] != 'X') {
                visit[nb][nc] = 1;
                q.push({ a + 1, nb, nc });
            }
        }
    }
}

vector<int> L, R;
vector<bool> check;

bool dfs(int v, int target) {

    check[v] = 1;

    for (auto i : adj[v]) {
        int a, b;
        tie(a, b) = i;
        if (b <= target && (R[a] == -1 || (!check[R[a]]  && dfs(R[a], target)))) {
            L[v] = a;
            R[a] = v;
            return 1;
        }
    }
    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        grid.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'C') {
                ptoci[{i, j}] = carcnt;
                citop[carcnt] = { i, j };
                carcnt++;
            }
            if (grid[i][j] == 'P') {
                ptopi[{i, j}] = parkcnt;
                pitop[parkcnt] = { i, j };
                parkcnt++;
            }
        }
    }

    if (carcnt == 0) {
        cout << 0;
        return 0;
    }

    adj = vector<vector<pair<int, int>>>(carcnt);

    for (int i = 0; i < carcnt; i++) {
        int x, y;
        tie(x, y) = citop[i];
        bfs(x, y, i);
    }

    // 이분탐색
    
    int l = 1, r = 2501;
    int ans = 2555;
    while (l <= r) {

        int mid = (l + r) / 2;
        L = vector<int>(carcnt, -1);
        R = vector<int>(parkcnt, -1);

        int ret = 0;
        for (int i = 0; i < carcnt; i++) {
            if (L[i] == -1) {
                check = vector<bool>(carcnt);
                if (dfs(i, mid)) ret++;
            }
        }

        if (ret == carcnt) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }

    if (ans != 2555) cout << ans;
    else cout << -1;
}