#include <bits/stdc++.h>
using namespace std;

vector<int> root, path;

int find(int n) {

	if (root[n] == n) return n;

	return find(root[n]);
}

void update(int n) {
	int t = find(n);

	if (t == root[n]) return;

	update(root[n]);
	path[n] += path[root[n]];
	root[n] = t;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {

		int n;
		cin >> n;

		root = vector<int>(n + 1);
		for (int i = 1; i <= n; i++) root[i] = i;
		
		path = vector<int>(n + 1);

		char c;
		cin >> c;
		while (c != 'O') {

			if (c == 'I') {
				int a, b;
				cin >> a >> b;

				path[a] = abs(b - a) % 1000 + path[b];
				root[a] = root[b];
			}
			else {
				int a;
				cin >> a;

				update(a);
				cout << path[a] << '\n';
			}

			cin >> c;
		}
	}
}