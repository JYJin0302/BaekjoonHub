#include <bits/stdc++.h>
using namespace std;

vector<int> root, cal, conn;

int find(int n) {
	if (root[n] == n) return n;

	return root[n] = find(root[n]);
}

void update(int n) {
	find(n);
	if (conn[n] == root[n]) return;

	update(conn[n]);
	cal[n] += cal[conn[n]];
	conn[n] = root[n];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;
	while (!(n == 0 && m == 0)) {
		root = vector<int>(n + 1);
		conn = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) root[i] = i, conn[i] = i;  // union find

		cal = vector<int>(n + 1);  // parent 와의 차이: i - parent[i]

		for (int i = 0; i < m; i++) {

			char c;
			cin >> c;

			int x, y, z;
			if (c == '!') {
				cin >> x >> y >> z;
				if (find(x) == find(y)) continue;

				update(x), update(y);
				int t = root[x];
				root[t] = root[y];
				conn[t] = root[y];
				cal[t] = cal[y] - cal[x] - z;
				
				update(x), update(y);
			}
			else {
				cin >> x >> y;
				if (find(x) != find(y)) cout << "UNKNOWN\n";
				else {
					update(x), update(y);
					cout << cal[y] - cal[x] << '\n';
				}
				
			}
		}
		cin >> n >> m;
	}

}