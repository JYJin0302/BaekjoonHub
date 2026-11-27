#include <bits/stdc++.h>
using namespace std;

int grid[8][8];
int n, m, ans = 64;
vector<pair<int, int>> cctv;
bool valid(int x, int y) {
	return (x >= 0 && x < n&& y >= 0 && y < m) && grid[x][y] != 6;
}

void operate(int cnt = 0) {

	if (cnt == cctv.size()) {
		int temp = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 0) temp++;
			}
		}

		ans = min(ans, temp);
		return;
	}

	// 0: up, 1: right, 2: down, 3: left
	int x, y;
	tie(x, y) = cctv[cnt];

	if (grid[x][y] == 1) {
		for (int i = 0; i < 4; i++) {
			int tx = x, ty = y;
			vector<pair<int, int>> cover;
			while (1) {
				switch (i) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = -1;
			}
			operate(cnt + 1);
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = 0;
			}
			cover.clear();
		}


	}
	else if (grid[x][y] == 2) {
		for (int i = 0; i < 2; i++) {
			int tx = x, ty = y;
			vector<pair<int, int>> cover;
			while (1) {
				switch (i) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			tx = x, ty = y;
			while (1) {
				switch (i+2) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = -1;
			}
			operate(cnt + 1);
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = 0;
			}
			cover.clear();
		}
	}
	else if (grid[x][y] == 3) {
		for (int i = 0; i < 4; i++) {
			int tx = x, ty = y;
			vector<pair<int, int>> cover;
			while (1) {
				switch (i) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			tx = x, ty = y;
			while (1) {
				switch ((i+1)%4) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = -1;
			}
			operate(cnt + 1);
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = 0;
			}
			cover.clear();
		}
	}
	else if (grid[x][y] == 4) {
		for (int i = 0; i < 4; i++) {
			int tx = x, ty = y;
			vector<pair<int, int>> cover;
			while (1) {
				switch (i) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			tx = x, ty = y;
			while (1) {
				switch ((i + 1)%4) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			tx = x, ty = y;
			while (1) {
				switch ((i + 2)%4) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = -1;
			}
			operate(cnt + 1);
			for (auto k : cover) {
				tie(tx, ty) = k;
				grid[tx][ty] = 0;
			}
			cover.clear();
		}
	}
	else if (grid[x][y] == 5) {
		vector<pair<int, int>> cover;
		int tx, ty;
		for (int i = 0; i < 4; i++) {
			tx = x, ty = y;

			while (1) {
				switch (i) {
				case 0:
					tx--;
					break;
				case 1:
					ty++;
					break;
				case 2:
					tx++;
					break;
				case 3:
					ty--;
					break;
				}
				if (valid(tx, ty)) {
					if (grid[tx][ty] == 0) cover.push_back({ tx, ty });
				}
				else break;
			}
		}
		for (auto k : cover) {
			tie(tx, ty) = k;
			grid[tx][ty] = -1;
		}
		operate(cnt + 1);
		for (auto k : cover) {
			tie(tx, ty) = k;
			grid[tx][ty] = 0;
		}
		cover.clear();
	}
}




int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> grid[i][j];
			if (grid[i][j] != 0 && grid[i][j] != 6) cctv.push_back({ i, j });
		}
	}
	operate();

	cout << ans;
}