#include <bits/stdc++.h>
using namespace std;

int n, k;
bool finish = 0;
int grid[12][12];
int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
vector<vector<vector<int>>> status;
map<int, tuple<int, int, int>> piece;

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

void move(int i, int cnt = 0) {
	int a,b,c;
	tie(a, b, c) = piece[i];
	bool rev = 0;

	int na = a + dx[c];
	int nb = b + dy[c];

	if (!inGrid(na, nb) || grid[na][nb] == 2) {
		if (cnt == 1) return;

		if (c < 2) c = 1 - c;
		else c = 5 - c;

		piece[i] = { a, b, c };
		move(i, cnt + 1);
		return;
	}
	else if (grid[na][nb] == 1) {
		rev = 1;
	}

	int idx = find(status[a][b].begin(), status[a][b].end(), i) - status[a][b].begin();
	vector<int> temp;
	if (rev) {
		for (int i = status[a][b].size() - 1; i >= idx; i--) temp.push_back(status[a][b][i]);
	}
	else {
		for (int i = idx; i < status[a][b].size(); i++) temp.push_back(status[a][b][i]);
	}

	while (status[a][b].size() > idx) status[a][b].pop_back();

	for (int i : temp) status[na][nb].push_back(i);

	if (status[na][nb].size() >= 4) finish = 1;

	for (int i : status[na][nb]) {
		int a, b, c;
		tie(a, b, c) = piece[i];
		piece[i] = { na, nb, c };
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;
	status = vector<vector<vector<int>>>(n, vector<vector<int>>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--, c--;
		piece[i+1] = { a, b, c };
		status[a][b].push_back(i + 1);
	}

	int cnt = 1;
	while (cnt <= 1000) {

		for (int i = 1; i <= k; i++) {
			move(i);

			if (finish) break;
		}
		if (finish) break;

		cnt++;
	}

	if (finish) cout << cnt;
	else cout << -1;

}