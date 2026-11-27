#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define x first
#define y second

vector<int> adj[300001];
int num[300001], sz[300001], root[300001];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

map<pair<int, int>, bool> invalid;
int o, ans;

vector<pair<int, int>> newEdge;

int dfs(int v, int pv = -1) {
    num[v] = o++;
    int res = num[v];

    for (auto i : adj[v]) {
        if (num[i] == 0) {
            int tmp = dfs(i, v);
            res = min(res, tmp);

            if (tmp > num[v]) {
                // 단절선 {v, i}
                newEdge.push_back({ min(v, i), max(v, i) });
            }
        }
        else if (i != pv) res = min(res, num[i]);
    }
    return res;
}

int dfs2(int v, int pv = -1) {

    num[v] = sz[v];

    for (auto i : adj[v]) if (i != pv) {

        int tmp = dfs2(i, v);
        if (tmp % 2 == 1) {
            invalid[{min(i, v), max(i, v)}] = 1;
            ans--;
        }
    
        num[v] += tmp+1;
    }

    return num[v];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edge(m);
    for (auto& i : edge) {
        cin >> i.x >> i.y;
        adj[i.x].push_back(i.y);
        adj[i.y].push_back(i.x);
        if (i.x > i.y)swap(i.x, i.y);
    }

    if (m % 2 == 0) {
        cout << 0;
        return 0;
    }

    o = 1;
    dfs(1);
    // 단절선 구함 : newEdge

    map<pair<int, int>, bool> isCut;
    for (auto i : newEdge) {
        isCut[i] = 1;
    }

    // make new graph
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 0;
    }

    for (auto i : edge) {
        if (!isCut[i]) {
            int a = i.x, b = i.y;
            a = find(a), b = find(b);

            // connect
            if (a != b) {
                sz[a] += sz[b] +1;
                root[b] = a;
            }
            else {
                sz[a]++;
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        adj[i].clear();
        num[i] = 0;
    }

    for (auto i : newEdge) {
        int a = i.x, b = i.y;
        a = find(a), b = find(b);

        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans = m;

    dfs2(find(1));

    cout << ans << '\n';
    for (int i = 0; i < m; i++) {
        int a = edge[i].x, b = edge[i].y;
        a = find(a), b = find(b);
        if (a > b) swap(a, b);

        if (!invalid[{a, b}]) cout << i + 1 << ' ';
    }

}