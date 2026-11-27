#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

int A[101010], B[101010];
vector<int> adj[101010];

int need[101010];
void dfs(int v, int pv = -1) {
    need[v] = B[v] - A[v];

    for (auto f : adj[v]) if (f != pv) {
        dfs(f, v);
        if (need[f] >= 0) {
            need[v] += need[f];
        }
    }
}
void solve() {

    int n, p;
    cin >> n >> p;

    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> B[i];
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(p);
    if (need[p] < 0) need[p] = 0;
    cout << need[p] << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
