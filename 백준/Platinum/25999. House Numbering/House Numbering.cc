#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<tuple<int, int, int>> edge;
vector<pair<int, int>> adj[100001];
int topo[100001];

vector<bool> vs;
map<pair<int, int>, int> ans;
map<pair<int, int>, int> edgeVal;
map<int, bool> isIn[100001];

vector<int> vx;
bool ok = 1;

void dfs(int v, int init, int pv = -1) {

    vx.push_back(v);
    vs[v] = 1;

    for (auto i : adj[v]) {
        int a, b;
        tie(a, b) = i;

        if (pv != a && !vs[a] && a != init) {
            dfs(a, init, v);
        }
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int a, b, h;
        cin >> a >> b >> h;

        edge.push_back({ a, b, h });
        edgeVal[{a, b}] = h;
        edgeVal[{b, a}] = h;

        adj[a].push_back({ b, h });
        adj[b].push_back({ a, h });

        topo[a]++, topo[b]++;
    }

    vs = vector<bool>(n + 1);
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (topo[i] == 1) {
            q.push(i);
        }
    }

    bool tok = 1;
    while (!q.empty()) {

        int a = q.front();
        q.pop();
        if (vs[a]) continue;
        vs[a] = 1;

        for (auto i : adj[a]) {
            int x, y;
            tie(x, y) = i;

            if (!vs[x]) {
                ans[{a, x}] = a;
                ans[{x, a}] = a;
                if (isIn[x][y]) tok = 0;
                else isIn[x][y] = 1;

                topo[x]--;
                if (topo[x] == 1) {
                    q.push(x);
                }
            }
        }
    }

    if (!tok) {
        cout << "impossible";
        return 0;
    }

    int ix = 1;
    while (vs[ix]) ix++;

    dfs(ix, ix);

    // ->
    bool ok = 1;
    int tsz = vx.size();
    for (int i = 0; i < tsz; i++) {

        int a = vx[i], b = vx[(i + tsz - 1) % tsz];
        int vv = edgeVal[{a, b}];
        if (isIn[b][vv]) ok = 0;
    }

    if (ok) {

        for (int i = 0; i < tsz; i++) {

            int a = vx[i], b = vx[(i + tsz - 1) % tsz];
            ans[{a, b}] = a;
            ans[{b, a}] = a;
        }

        for (auto i : edge) {
            int a, b, c;
            tie(a, b, c) = i;
            cout << ans[{a, b}] << ' ';
        }
        return 0;

    }

    ok = 1;
    for (int i = 0; i < tsz; i++) {

        int a = vx[i], b = vx[(i + 1) % tsz];
        int vv = edgeVal[{a, b}];
        if (isIn[b][vv]) ok = 0;
    }

    if (ok) {

        for (int i = 0; i < tsz; i++) {

            int a = vx[i], b = vx[(i + 1) % tsz];
            ans[{a, b}] = a;
            ans[{b, a}] = a;
        }

        for (auto i : edge) {
            int a, b, c;
            tie(a, b, c) = i;
            cout << ans[{a, b}] << ' ';
        }
        return 0;

    }

    cout << "impossible";
}