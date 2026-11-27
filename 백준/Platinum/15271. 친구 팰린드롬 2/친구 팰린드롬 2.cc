#include <bits/stdc++.h>
using namespace std;

// 0 : s, 201 : t
int c[202][202];
int f[202][202];

int main() {

	int n, m;
	cin >> n >> m;

	vector<vector<int>> adj(202);

	for(int i= 0; i < m; i++){
		int a, b;
		cin >> a >> b;
        
        if (a % 2 == b% 2) continue;
        
		adj[a].push_back(b);
		adj[b].push_back(a);
        
        if (b % 2 == 1) swap(a, b);
		c[a][b] = 1;
	}

	for (int i = 1; i <= n; i += 2) {
		adj[0].push_back(i);
		adj[i].push_back(0);
		c[0][i] = 1;
		c[i][0] = 1;
	}

	for (int i = 2; i <= n; i += 2) {
		adj[i].push_back(201);
		adj[201].push_back(i);
		c[i][201] = 1;
	}

	int ans = 0;
	while (1) {
		vector<int> from(202, -1);
		from[0] = 0;
		queue<int> q;

		q.push(0);

		while (!q.empty()) {

			int a = q.front();
			q.pop();
			if (a == 201) break;
			for (auto i : adj[a]) if (from[i] == -1 && c[a][i] - f[a][i] > 0) {
				from[i] = a;
				q.push(i);
			}
		}

		if (from[201] == -1) break;

		ans++;
		int x = 201;
		while (x != 0) {
			f[from[x]][x] += 1;
			f[x][from[x]] -= 1;
			x = from[x];
		}

	}
	ans *= 2;

	cout << min(ans + 1, n);


}