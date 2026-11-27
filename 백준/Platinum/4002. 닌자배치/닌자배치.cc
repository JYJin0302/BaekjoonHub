#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll A[100001], tot[100001], sz[100001];
ll ans = 0;

ll n, t;
priority_queue<int> tmp[100001];
vector<int> adj[100001];

void dfs(int v, int pv = -1) {

    for (auto i : adj[v]) if (i != pv) {
        dfs(i, v);

        if (sz[v] < sz[i]) {
            swap(tmp[i], tmp[v]);
            swap(sz[i], sz[v]);
            swap(tot[i], tot[v]);
        }
        // i -> v

        tot[v] += tot[i];
        sz[v] += sz[i];
        while(!tmp[i].empty()){
            tmp[v].push(tmp[i].top());
            tmp[i].pop();
        }

        while (tot[v] > t) {
            sz[v]--;
            tot[v] -= tmp[v].top();
            tmp[v].pop();
        }

    }
    ans = max(ans, sz[v] * A[v]);
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        A[i] = c;
        adj[a].push_back(i);
        if (b < t) {
            tmp[i].push(b);
            tot[i] = b;
            sz[i] = 1;
        }
    }

    dfs(1);

    cout << ans;
}