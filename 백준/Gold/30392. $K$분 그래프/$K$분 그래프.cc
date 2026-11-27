#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mp make_pair
#define all(x) x.begin(), x.end()

bool ok = 1;
bool chk[302020][2];

vector<pair<int, int>> adj[303030];
void dfs(int v, int p = 0) {
    chk[v][p] = 1;
    for (auto&[a, b] : adj[v]) {
        int np = p ^ b;
        if (!chk[a][np]) {
            dfs(a, np);
        }
    }
}

void solve() {

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if (c % k == 0) {
            c = 0;
        }
        else if (c * 2 % k == 0) {
            c = 1;
        }
        else {
            c = 0;
            ok = 0;
        }
        adj[a].push_back(mp(b, c));
        adj[b].push_back(mp(a, c));
    }

    for (int i = 1; i <= n; i++) {
        if (!chk[i][0] && !chk[i][1]) {
            dfs(i, 0);
        }
    }
    for (int i = 1; i <= n; i++) {
        if (chk[i][0] && chk[i][1]) ok = 0;
    }

    if (!ok) cout << "No\n";
    else cout << "Yes\n";
}

int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    solve();
    return 0;
}
