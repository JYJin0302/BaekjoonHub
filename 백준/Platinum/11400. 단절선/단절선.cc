#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

vector<int> adj[101010];
int minV[101010];
bool vis[101010];
int visOrd[101010];
int ord = 0;
vector<pair<int, int>> cEdg;

int dfs(int v, int pv = -1) {
    minV[v] = ++ord;
    visOrd[ord] = v;
    vis[v] = 1;
    int ret = ord;

    int cnt = 0;
    for (auto f : adj[v]) {
        if (f == pv && cnt == 0) {
            cnt++;
            continue;
        }
        if (!vis[f]) {
            int ta = dfs(f, v);
            if (ta > minV[v]) {
                cEdg.push_back(mp(min(v, f), max(v, f)));
            }
            ret = min(ret, ta);
        }
        else ret = min(ret, minV[f]);
    }
    return ret;
}

void solve() {

    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> edg;
    while (m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        edg.push_back(mp(a, b));
    }

    dfs(1);

    sort(all(cEdg));
    cout << cEdg.size() << '\n';
    for (auto& [a, b] : cEdg) {
        cout << a << ' ' << b << '\n';
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while (t--) solve();
}