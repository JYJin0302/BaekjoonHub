#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
bool vs[1505][1505];
int idx[1505][1505];

vector<int> root;
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

void solve() {

	cin >> n >> m;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	int cnt = 0;
	vector<int> tdx;

	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (A[i][j] == 'X' || vs[i][j]) continue;
			cnt++;
			vs[i][j] = 1;
			q.push({ i, j });
			while (!q.empty()) {

				int a, b;
				tie(a, b) = q.front();
				q.pop();

				idx[a][b] = cnt;
				if (A[a][b] == 'L') tdx.push_back(cnt);

				for (int k = 0; k < 4; k++) {
					int na = a + dx[k];
					int nb = b + dy[k];

					if (inGrid(na, nb) && !vs[na][nb] && A[na][nb] != 'X') {
						vs[na][nb] = 1;
						q.push({ na, nb });
					}
				}
			}
		}
	}

	int ix1 = tdx[0], ix2 = tdx[1];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i][j] != 'X') q.push({ i, j });
		}
	}

	root = vector<int>(cnt + 1);
	for (int i = 1; i <= cnt; i++) root[i] = i;

	//cout << ix1 << ' ' << ix2 << '\n';

	int ans = 0;
	while (1) {

		queue<pair<int, int>> tq;
		while (!q.empty()) {

			int a, b;
			tie(a, b) = q.front();
			q.pop();
			tq.push({ a, b });

			for (int k = 0; k < 4; k++) {
				int na = a + dx[k];
				int nb = b + dy[k];

				if (inGrid(na, nb)) {
					if (idx[na][nb]) {
						int t1 = idx[a][b], t2 = idx[na][nb];

						t1 = find(t1), t2 = find(t2);
						root[t1] = t2;
					}
				}
			}
		}

		/*
		cout << "CURR\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << idx[i][j];
			}
			cout << '\n';
		}
		*/

		if (find(ix1) == find(ix2)) break;

		ans++;

		while (!tq.empty()) {

			int a, b;
			tie(a, b) = tq.front();
			tq.pop();

			for (int k = 0; k < 4; k++) {
				int na = a + dx[k];
				int nb = b + dy[k];

				if (inGrid(na, nb) && !vs[na][nb]) {
					idx[na][nb] = idx[a][b];
					vs[na][nb] = 1;
					q.push({ na, nb });
				}
			}
		}
	}
	cout << ans;


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