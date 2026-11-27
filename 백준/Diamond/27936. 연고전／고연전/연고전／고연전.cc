#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<vector<int>> adj;

int c[203][203];
int f[203][203];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, K;
	cin >> N >> M >> K;

	adj = vector<vector<int>>(201);
	for (int i = 1; i <= K; i++) {
		int a, b;
		cin >> a >> b;
		b += 100;

		adj[a].push_back(b);
		adj[b].push_back(a);
		c[a][b] = 1e6;
	}


	for (int i = 1; i <= M; i++) {
		adj[0].push_back(i);
		c[0][i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		adj[i + 100].push_back(201);
		c[i + 100][201] = 1;
	}

	int ans = N + 10, ansi = 0;
	for (int usd = 1; usd <= M; usd++) {
		// use i member of korea
		c[0][usd] = 1e6;

		memset(f, 0, sizeof(f));

		int tans = 0;
		while (1) {

			vector<int> from(203, -1);
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

			tans++;

			int x = 201;
			while (x != 0) {
				f[from[x]][x]++;
				f[x][from[x]]--;
				x = from[x];
			}
		}

		c[0][usd] = 1;
		/*

		cout << "USED: " << usd << ' ' << tans << '\n';
		cout << "K: ";
		for (int i = 1; i <= M; i++) {
			if (f[0][i]) cout << i << ' ';
		}
		cout << '\n';
		cout << "Y: ";
		for (int i = 1; i <= N; i++) {
			if (f[i+100][201]) cout << i << ' ';
		}
		cout << '\n';
		*/

		if (ans > tans) {
			ansi = usd;
			ans = tans;
		}
	}



	c[0][ansi] = 1e6;

	memset(f, 0, sizeof(f));
	vector<int> res = {};
	while (1) {

		vector<int> from(203, -1);
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

		if (from[201] == -1) {
			for (int i = 1; i <= M; i++) {
				if (from[i] != -1) res.push_back(i);
			}

			break;
		}

		int x = 201;
		while (x != 0) {
			f[from[x]][x]++;
			f[x][from[x]]--;
			x = from[x];
		}
	}

	//cout << ansi << '\n';

	cout << res.size() << '\n';
	for (auto i : res) cout << i << ' ';;
}