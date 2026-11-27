#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define mp make_pair
#define all(x) x.begin(), x.end()

vector<int> C[1010], R[1010];

int root[1010];
int find(int n) {
    if (root[n] == n) return n;
    return root[n] = find(root[n]);
}


vector<int> adj[1010];
bool vs[1010];
int L[1010];

bool go(int v) {
    if (vs[v]) return 0;
    vs[v] = 1;

    for (auto f : adj[v]) {
        if (L[f] == -1 || go(L[f])) {
            L[f] = v;
            return 1;
        }
    }
    return 0;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> A(m);
    for (auto& i : A) cin >> i.first >> i.second;

    for (int i = 0; i < m; i++) root[i] = i;
    for (int i = 0; i < m; i++) {
        auto& [a, b] = A[i];
        R[a].push_back(i);
        C[b].push_back(i);
        adj[a].push_back(b);
    }

    int mx = 0, mn = 0;
    for (int i = 1; i <= n; i++) {
        for (auto j = 1; j < R[i].size(); j++) {
            int a = find(R[i][j - 1]);
            int b = find(R[i][j]);
            if (a != b) {
                root[b] = a;
                mx++;
            }
        }
        for (auto j = 1; j < C[i].size(); j++) {
            int a = find(C[i][j - 1]);
            int b = find(C[i][j]);
            if (a != b) {
                root[b] = a;
                mx++;
            }
        }
    }
    
    memset(L, -1, sizeof(L));
    for (int i = 1; i <= n; i++) {
        if (adj[i].empty()) continue;
        for (int j = 1; j <= n; j++) {
            vs[j] = 0;
        }
        if (go(i)) {
            mn++;
        }
    }
    mn = m - mn;

    cout << mn << ' ' << mx << '\n';



}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    //cin >> t;
    while (t--) solve();
}