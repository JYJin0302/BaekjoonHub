#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> adj[1010];
int L[1010], R[1010];

vector<bool> vs;

bool dfs(int v, int curr = -1) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto i : adj[v]) {
        if (i == curr) continue;
        if (R[i] == 0 || dfs(R[i])) {
            L[v] = i;
            R[i] = v;
            return 1;
        }
    }
    return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;

            adj[i].push_back(x);
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        vs = vector<bool>(n + 1);
        if (dfs(i)) cnt++;
    }

    bool ok = 1;
    if (cnt != n) ok = 0;
    for (int i = 1; i <= n; i++) {
        vs = vector<bool>(n + 1);
        
        R[L[i]] = 0;
        if (dfs(i, L[i])) {
            ok = 0;
        }
        else R[L[i]] = i;
    }

    if (ok) {
        cout << "1\n";
        for (int i = 1; i <= n; i++) cout << L[i] << ' ';
    }
    else cout << -1;
}