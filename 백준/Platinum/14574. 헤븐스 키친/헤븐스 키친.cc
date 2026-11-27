#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> root;

int find(int n) {
    if (root[n] == n) return n;

    return root[n] = find(root[n]);
}

vector<vector<int>> adj;
vector<pair<int, int>> vans;
void dfs(int v = 0, int pv = -1) {

    for (int i : adj[v]) if (i != pv) {
        
        dfs(i, v);
        vans.push_back({ v + 1, i+1 });
    }
}

int main() {

     ios::sync_with_stdio(false);
    cin.tie(nullptr);  int n;
    cin >> n;

    vector<pair<int, int>>A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i].first >> A[i].second;
    }

    vector<tuple<int, int, int>> edge;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edge.push_back({ (A[i].second + A[j].second) / abs(A[i].first - A[j].first), i, j });
        }
    }

    sort(edge.rbegin(), edge.rend());
    root = vector<int>(n);
    for (int i = 0; i < n; i++) root[i] = i;

    ll ans = 0;
    adj = vector<vector<int>>(n);
    for (auto i : edge) {
        int a, b, c;
        tie(a, b, c) = i;
        
        if (find(b) == find(c)) continue;

        ans += a;
        adj[b].push_back(c);
        adj[c].push_back(b);
        root[root[b]] = root[c];
    }

    dfs();

    cout << ans << '\n';
    for (auto i : vans) {
        cout << i.first << ' ' << i.second << '\n';
    }

}