#include <bits/stdc++.h>
using namespace std;

int hor[1001][1001];
int ver[1001][1001];
int rep[1000001];

vector<int> adj[1000001], rev[1000001];
set<int> f[1000001];

vector<bool> vs;
stack<int> st;
void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i != pv && !vs[i]) {
        vs[i] = 1;
        dfs(i, v);
    }
    st.push(v);
}

void dfs2(int v, int pv = -1) {
    for (auto i : rev[v]) if (i != pv && !vs[i]) {
        vs[i] = 1;
        rep[i] = rep[v];
        dfs2(i, v);
    }
}

int yellowblue(int n, int m, std::vector<std::string> grid)
{
    
    vector<pair<int, int>> edge;

    int cnt = 0;
    // make node
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            if (grid[i][j] == '#') continue;

            if (j == 0 || grid[i][j - 1] == '#') {
                // make horizontal
                hor[i][j] = ++cnt;
               // cout << "idx: " << cnt << ": " << i << ' ' << j << " -> ";
                int tj = j;
                while (tj < m && grid[i][tj] == '.') {
                    hor[i][tj] = cnt;
                    tj++;
                }
               // cout << i << ' ' << tj - 1 << '\n';
            }

            if (i == 0 || grid[i - 1][j] == '#') {
                ver[i][j] = ++cnt;
                int ti = i;
               // cout << "idx: " << cnt << ": " << i << ' ' << j << " -> ";
                while (ti < n && grid[ti][j] == '.') {
                    ver[ti][j] = cnt;
                    ti++;
                }
               // cout << ti - 1 << ' ' << j << '\n';
            }

            // connect
            bool vert = 0, hori = 0;
            if (i == 0 || grid[i - 1][j] == '#') hori = 1;
            if (i == n - 1 || grid[i + 1][j] == '#') hori = 1;

            if (j == 0 || grid[i][j - 1] == '#') vert = 1;
            if (j == m - 1 || grid[i][j + 1] == '#') vert = 1;

            if (hori) {
              //  cout << "Conn: " << ver[i][j] << ' ' << hor[i][j] << '\n';
                edge.push_back({ ver[i][j], hor[i][j] });
                adj[ver[i][j]].push_back(hor[i][j]);
                rev[hor[i][j]].push_back(ver[i][j]);
            }
            if (vert) {
             //  cout << "conn: " << hor[i][j] << ' ' << ver[i][j] << '\n';
                edge.push_back({ hor[i][j], ver[i][j]});
                adj[hor[i][j]].push_back(ver[i][j]);
                rev[ver[i][j]].push_back(hor[i][j]);
            }

        }
    }

        vs = vector<bool>(cnt + 1);
        for (int i = 1; i <= cnt; i++) {
            if (!vs[i]) {
                vs[i] = 1;
                dfs(i);
            }
        }

        vector<int> path;
        vs = vector<bool>(cnt + 1);
        while (!st.empty()) {
            int a = st.top();
            st.pop();

            if (vs[a]) continue;
            vs[a] = 1;
            rep[a] = a;
            path.push_back(a);
            dfs2(a);
        }

        for (auto i : edge) {
            int a, b;
            tie(a, b) = i;

            a = rep[a];
            b = rep[b];

            if (a != b) {
                f[a].insert(b);
            }
        }
        vector<int> topo(cnt + 1);
        //cout << "ADJ: \n";
        for (int i = 1; i <= cnt; i++) {
            if (rep[i] != i) continue;
            for (auto k : f[i]) {
                //cout << k << ' ';
                topo[k]++;
            }
            //cout << '\n';
        }

        int ok = 1;
        queue<int> q;
        
        for (int i = 1; i <= cnt; i++) if (rep[i] == i && topo[i] == 0) q.push(i);
        while (!q.empty()) {

            if (q.size() != 1) {
                ok = 0;
                break;
            }

            int a = q.front();
            q.pop();

            for (auto k : f[a]) {
                topo[k]--;
                if (topo[k] == 0) q.push(k);
            }
        }

    return ok;
}

