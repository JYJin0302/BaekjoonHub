#include <bits/stdc++.h>
using namespace std;

int n, m, k, x, y, z;
int N[11][11];
int updateN[11][11];
vector<int> tree[11][11];

bool outofgrid(int r, int c) {
	return (r < 1 || r > n) || (c < 1 || c > n);
}

void spring_summer() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sort(tree[i][j].begin(), tree[i][j].end());
			bool eat = 1;
			int cnt = 0;
			for (int t : tree[i][j]) {
				if (N[i][j] < t) eat = 0;
				if (eat) {
					cnt++;
					N[i][j] -= t;
				}
				else {
					N[i][j] += t / 2;
				}
			}
			for (int k = 0; k < cnt; k++) {
				tree[i][j][k]++;
			}
			while (tree[i][j].size() > cnt) {
				tree[i][j].erase(tree[i][j].end() - 1);
			}
		}
	}
}

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { 1, 0, -1, -1, -1, 0, 1, 1 };

void autumn() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int age : tree[i][j]) {
				if (age % 5 == 0) {
					for (int k = 0; k < 8; k++) {
						int newi = i + dx[k];
						int newj = j + dy[k];
						if (!outofgrid(newi, newj)) {
							tree[newi][newj].push_back(1);
						}
					}
				}
			}
		}
	}
}

void winter() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			N[i][j] += updateN[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

	
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> updateN[i][j];
			N[i][j] = 5;
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> x >> y >> z;
		tree[x][y].push_back(z);
	}

	while (k--) {
		spring_summer();
		autumn();
		winter();
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += tree[i][j].size();
		}
	}
	cout << ans;
}