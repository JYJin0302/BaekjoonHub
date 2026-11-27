#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair

int G[404], B[404], L[404], U[404], R[404];
vector<int> adj[404];
bool vs[404];


bool go(int x) {

    if (vs[x]) return 0;
    vs[x] = 1;

    for (auto f : adj[x]) {
        if (R[f] == 0 || go(R[f])) {
            R[f] = x;
            return 1;
        }
    }
    return 0;
}

void solve() {

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> G[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> B[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> L[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> U[i];
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (L[i] > B[j] && U[j] < G[i]) adj[i].push_back(j);
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        memset(vs, 0, sizeof(vs));

        if (go(i)) ans++;
    }
    cout << ans;

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) solve();
    return 0;
}
