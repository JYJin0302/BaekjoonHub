#include <bits/stdc++.h>
using namespace std;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int n, m;
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;

        adj[b].push_back(a);
    }


    vector<int> ans(n + 1);
    for (int i = 1; i <= n; i++) {

        vector<bool> v(n + 1);
        v[i] = 1;

        queue<int> q;
        q.push(i);
        while (!q.empty()) {

            int a = q.front();
            q.pop();

            for (int j : adj[a]) if (!v[j]) {
                v[j] = 1;
                q.push(j);
            }
        }

        int cnt = 0;
        for (int j = 1; j <= n; j++) cnt += v[j];

        ans[i] = cnt;
    }

    int maxn = *max_element(ans.begin(), ans.end());
    for (int i = 1; i <= n; i++) {
        if (ans[i] == maxn) cout << i << ' ';
    }
}