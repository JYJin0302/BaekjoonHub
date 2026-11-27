#include <bits/stdc++.h>
using ll = long long;
using namespace std;

#define INF 100000000
#define pb push_back
#define all(x) (x).begin(),(x).end()

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0 };



void solve() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    vector<int> inp(m);
    vector<int> topo(m);
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;

        vector<int> temp(t);
        for (auto& k : temp) cin >> k;

        int k;
        cin >> k;
        topo[i] = t;
        inp[i] = k;

        for (int j : temp) {
            adj[j].pb(i);
        }
    }
    vector<bool> used(n + 1);
    vector<int> ans;
    int l;
    cin >> l;
    queue<int> q;
    for (int i = 0; i < l; i++) {
        int x;
        cin >> x;
        q.push(x);
        used[x] = 1;
    }

    while (!q.empty()) {
        int a = q.front();
        q.pop();
        ans.pb(a);
        for (int i : adj[a]) {
            topo[i]--;
            if (topo[i] == 0 && !used[inp[i]]) {
                q.push(inp[i]);
                used[inp[i]] = 1;
            }
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (int i : ans) cout << i << ' ';

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T = 1;
	//cin >> T;

	while (T--) {
		solve();
	}
}