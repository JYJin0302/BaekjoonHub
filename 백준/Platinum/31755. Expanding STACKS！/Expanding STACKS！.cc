#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define mp make_pair
#define all(x) x.begin(), x.end()
#define x first
#define y second

int I[1010], O[1010];
int col[1010];

vector<int> adj[1010];
void dfs(int v) {
    for (auto f : adj[v]) {
        if (col[f] == 0) {
            col[f] = 3 - col[v];
            dfs(f);
        }
        else if (col[f] != 3 - col[v]) {
            cout << '*';
            exit(0);
        }
    }
}

void solve() {

    int n;
    cin >> n;

    for (int i = 1; i <= n * 2; i++) {
        int x;
        cin >> x;
        if (x > 0) I[x] = i;
        else O[-x] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            int ti = i, tj = j;
            if (I[ti] > I[tj]) swap(ti, tj);

            if (O[ti] > I[tj] && O[ti] < O[tj]) {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] == 0) {
            col[i] = 1;
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (col[i] == 1) cout << "G";
        else cout << "S";
    }
    cout << '\n';
    

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}