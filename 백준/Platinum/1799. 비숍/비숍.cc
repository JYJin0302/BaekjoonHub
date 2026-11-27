#include <bits/stdc++.h>
using namespace std;

int n, ansB = 0, ansW = 0;

int grid[10][10];
vector<pair<int, int>> black;
vector<pair<int, int>> white;
vector<bool> used;

int dx[] = { -1, -1, 1, 1 };
int dy[] = { -1, 1, -1, 1 };

bool valid(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < n);
}

void backtrackB(int f = -1) {

	if (f == black.size() - 1) {
		int temp = 0;
		for (int i = 0; i < black.size(); i++) {
			if (used[i]) temp++;
		}
		ansB = max(ansB, temp);
		return;
	}

	for (int m = f + 1; m < black.size(); m++) {
		int a, b;
		tie(a, b) = black[m];
		if (grid[a][b] == -1) {
			if (m == black.size() - 1) {
				int temp = 0;
				for (int i = 0; i < black.size(); i++) {
					if (used[i]) temp++;
				}
				ansB = max(ansB, temp);
				return;
			}
			continue;
		}
		else {
			vector<pair<int, int>> diff;

			for (int i = 0; i < 4; i++) {
				int ta = a, tb = b;
				while (1) {
					ta += dx[i];
					tb += dy[i];
					if (valid(ta, tb)) {
						if (grid[ta][tb] != -1) diff.push_back({ ta, tb });
					}
					else {
						break;
					}
				}
			}

			for (auto i : diff) {
				tie(a, b) = i;
				grid[a][b] = -1;
			}
			used[m] = 1;
			backtrackB(m);
			used[m] = 0;
			for (auto i : diff) {
				tie(a, b) = i;
				grid[a][b] = 0;
			}
			diff.clear();
		}
	}
}
void backtrackW(int f = -1) {

	if (f == white.size() - 1) {
		int temp = 0;
		for (int i = 0; i < white.size(); i++) {
			if (used[i]) temp++;
		}
		ansW = max(ansW, temp);
		return;
	}

	for (int m = f + 1; m < white.size(); m++) {
		int a, b;
		tie(a, b) = white[m];
		if (grid[a][b] == -1) {
			if (m == white.size() - 1) {
				int temp = 0;
				for (int i = 0; i < white.size(); i++) {
					if (used[i]) temp++;
				}
				ansW = max(ansW, temp);
				return;
			}
			continue;
		}
		else {
			vector<pair<int, int>> diff;

			for (int i = 0; i < 4; i++) {
				int ta = a, tb = b;
				while (1) {
					ta += dx[i];
					tb += dy[i];
					if (valid(ta, tb)) {
						if (grid[ta][tb] != -1) diff.push_back({ ta, tb });
					}
					else {
						break;
					}
				}
			}

			for (auto i : diff) {
				tie(a, b) = i;
				grid[a][b] = -1;
			}
			used[m] = 1;
			backtrackW(m);
			used[m] = 0;
			for (auto i : diff) {
				tie(a, b) = i;
				grid[a][b] = 0;
			}
			diff.clear();
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
			if (grid[i][j] == 1) {
				if ((i + j) % 2 == 0) black.push_back({ i, j });
				else white.push_back({ i, j });
			}
		}
	}

	used = vector<bool>(black.size());

	backtrackB();

	used = vector<bool>(white.size());

	backtrackW();
	cout << ansB + ansW;
}