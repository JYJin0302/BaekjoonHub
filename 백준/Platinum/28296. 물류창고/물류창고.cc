#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge {
    ll cost;
    int u, v;

    bool operator<(Edge& other) {
        return cost > other.cost;
    }
};

int group[100001];
int root[100001];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}

ll ans[50001];
int sz[100001];
map<ll, ll> tmp[100001];

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k, m;
    cin >> n >> k >> m;

    for (int i = 1; i <= n; i++) {
        cin >> group[i];
        tmp[i][group[i]] = 1;
        sz[i] = 1;
        root[i] = i;
    }

    vector<Edge> A(m);
    for (auto& i : A) {
        cin >> i.u >> i.v >> i.cost;
    }

    sort(A.begin(), A.end());

    for (auto i : A) {
        int u = find(i.u), v = find(i.v);
        
        if (u == v) continue;
        
        if (sz[u] > sz[v]) {
            swap(u, v);
        }
        // u -> v

        for (auto j = tmp[u].begin(); j != tmp[u].end(); j++) {
            ll cnt = tmp[v][j->first] * j->second;
            ans[j->first] += cnt * i.cost;
        }
        for (auto j = tmp[u].begin(); j != tmp[u].end(); j++) {
            tmp[v][j->first] += j->second;
        }

        sz[v] += sz[u];
        root[u] = v;
    }

    for (int i = 1; i <= k; i++) cout << ans[i] << '\n';

}