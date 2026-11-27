#include <bits/stdc++.h>
using namespace std;

int path[60][60];
int flow[60][60];

int toi(char c) {
	if (c >= 'a' && c <= 'z') {
		return c - 'a' + 26;
	}
	return c - 'A';
}

int main() {

	int n;
	cin >> n;

	memset(path, 0, sizeof(path));
	memset(flow, 0, sizeof(flow));

	for (int i = 0; i < n; i++) {
		char c1, c2;
		int x;
		cin >> c1 >> c2 >> x;

		int a = toi(c1), b = toi(c2);
		path[a][b] += x;
		path[b][a] += x;
	}



	int ans = 0;
	while (1) {

		vector<int> from(60, -1);
		queue<int> q;
		q.push(0);
		from[0] = 0;

		while (!q.empty()) {
			int a = q.front();
			q.pop();

			if (a == 25)break;

			for (int i = 0; i < 52; i++) {
				if (path[a][i] - flow[a][i] > 0 && from[i] == -1) {
					from[i] = a;
					q.push(i);
				}
			}
		}

		if (from[25] == -1) break;

		int x = 25;
		int tans = 1000000000;
		while (x != 0) {
			tans = min(tans, path[from[x]][x] - flow[from[x]][x]);
			x = from[x];
		}

		ans += tans;

		x = 25;
		while (x != 0) {
			flow[from[x]][x] += tans;
			flow[x][from[x]] -= tans;
			x = from[x];
		}
	}

	cout << ans;
}