#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int x) {
	if (root[x] == x) return x;

	return root[x] = find(root[x]);
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, m, k;
	cin >> n >> m >> k;
	while (!(n == 0 && m == 0 && k == 0)) {

		root = vector<int>(n + 1);

		vector<tuple<int, int, int>> edge;
		for (int i = 0; i < m; i++) {
			char c;
			int a, b;
			cin >> c >> a >> b;

			int nc = (c == 'B');
			edge.push_back({ nc, a, b });
		}

		// min
		sort(edge.begin(), edge.end());
		for (int i = 0; i <= n; i++) root[i] = i;

		int minn = 0;
		for (auto i : edge) {
			int c, a, b;
			tie(c, a, b) = i;

			find(a), find(b);
			if (root[a] != root[b]) {
				minn += (c == 1);
				root[root[a]] = root[b];
			}
		}

		// max
		sort(edge.rbegin(), edge.rend());
		for (int i = 0; i <= n; i++) root[i] = i;

		int maxn = 0;
		for (auto i : edge) {
			int c, a, b;
			tie(c, a, b) = i;

			find(a), find(b);
			if (root[a] != root[b]) {
				maxn += (c == 1);
				root[root[a]] = root[b];
			}
		}

		if (k >= minn && k <= maxn) cout << "1\n";
		else cout << "0\n";

		cin >> n >> m >> k;
	}
} 