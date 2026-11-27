#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    int u, v;
    int t;
};

vector<pair<int, int>> adj[100001];
int val[100001];
void dfs(int v, int pv = -1) {
    for (auto i : adj[v]) if (i.first != pv) {
        val[i.first] = val[v] ^ i.second;
        dfs(i.first, v);
    }
}

int root[100001], sz[100001];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}
map<int, ll> tmp[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<Edge> A(n-1);
    for (auto& i : A) {
        cin >> i.u >> i.v >> i.t;
        adj[i.u].push_back({ i.v, i.t });
        adj[i.v].push_back({ i.u, i.t });
    }
    vector<int>p(n - 1);
    for (auto& i : p) {
        cin >> i;
        i--;
    }
    dfs(1);
    
    for (int i = 1; i <= n; i++) {
        root[i] = i;
        sz[i] = 1;
        tmp[i][val[i]] = 1;
    }
    vector<ll> ans = { 0 };
    for (int i = n - 2; i >= 0; i--) {
        ll tans = 0;
        int u = find(A[p[i]].u), v = find(A[p[i]].v);
        
        if (sz[u] > sz[v]) swap(u, v);
        // u -> v

        for (auto k = tmp[u].begin(); k != tmp[u].end(); k++) {
            tans += tmp[v][k->first]*k->second;
            tmp[v][k->first] += k->second;
        }

        ans.push_back(tans + ans.back());
        root[u] = v;
        sz[v] += sz[u];
    }

    reverse(ans.begin(), ans.end());
    for (auto i : ans) cout << i << '\n';
}