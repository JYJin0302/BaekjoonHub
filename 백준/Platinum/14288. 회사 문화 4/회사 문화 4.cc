#include <bits/stdc++.h>
using ll = long long;
using namespace std;

int n, m;
vector<int> adj[100001];
vector<int> fw_1, fw_2;

void update(int ix, int v, vector<int>& fw) {
    while (ix <= 2*n) {
        fw[ix] += v;
        ix += ix & -ix;
    }
}

int ssum(int ix, vector<int>& fw) {
    int res = 0;
    while (ix) {
        res += fw[ix];
        ix -= ix & -ix;
    }
    return res;
}

int s[100001], e[100001];
int o = 1;
void dfs(int v, int pv = -1) {
    s[v] = o++;
    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);
    }
    e[v] = o++;
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    fw_1 = vector<int>(n*2 + 1);
    fw_2 = vector<int>(n*2 + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (x != -1) {
            adj[i].push_back(x);
            adj[x].push_back(i);
        }
    }

    dfs(1);

    int dir = 1;
    while (m--) {

        int t,a ,b;
        cin >> t;
        
        if (t == 1) {
            cin >> a >> b;

            if (dir) {
                update(s[a], b, fw_1);
                update(e[a], -b, fw_1);
            }
            else {
                update(s[a], b, fw_2);
                update(e[a], b, fw_2);
            }

        }
        else if (t == 2) {
            cin >> a;

            int res = 0;
            res = ssum(s[a], fw_1) + (ssum(e[a], fw_2) - ssum(s[a]-1, fw_2)) / 2;
            cout << res << '\n';

        }
        else {
            dir = 1 - dir;
        }
    }
}