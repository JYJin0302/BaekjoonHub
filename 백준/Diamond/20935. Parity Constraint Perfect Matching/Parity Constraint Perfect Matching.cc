#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<int, int>> adj[510];
pair<int, int> L[510], R[510];

vector<bool> vs;

bool dfs(int v) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto &[a,b] : adj[v]) {
        if (R[a].first == 0 || dfs(R[a].first)) {
            L[v] = { a, b };
            R[a] = { v, b };
            return 1;
        }
    }
    return 0;
}

bool dfs2(int v, int tar = 0) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto& [a, b] : adj[v]) {
        if (R[a].first == 0 && b == tar){
            L[v] = { a, b };
            R[a] = { v, b };
            return 1;
        }
        if (dfs2(R[a].first, tar ^ b ^ R[a].second)) {
            L[v] = { a, b };
            R[a] = { v, b };
            return 1;
        }

    }
    return 0;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        c %= 2;

        adj[a].push_back({ b, c });
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        vs = vector<bool>(n + 1);
        if (dfs(i)) cnt++;
    }

    if (cnt != n) {
        cout << "-1\n-1";
        return 0;
    }

    vector<pair<int, int>> odd, even;
    
    int curr = 0;
    for (int i = 1; i <= n; i++) {
        curr ^= L[i].second;
    }

    
    for (int i = 1; i <= n; i++) odd.push_back({ i, L[i].first });

    for (int i = 1; i <= n; i++) {
        int curr = L[i].second;
        R[L[i].first] = { 0, 0 };
        vs = vector<bool>(n + 1);
        if (dfs2(i, curr ^ 1)) {
            for (int j = 1; j <= n; j++) {
                even.push_back({ j, L[j].first });
            }
            break;
        }
        R[L[i].first] = { i, curr };
    }
    
    if (!curr) swap(odd, even);

    if (even.empty()) cout << "-1\n";
    else for (auto [a, b] : even) cout << a << ' ' << b << '\n';
    if (odd.empty()) cout << "-1\n";
    else for (auto [a, b] : odd) cout << a << ' ' << b << '\n';
}