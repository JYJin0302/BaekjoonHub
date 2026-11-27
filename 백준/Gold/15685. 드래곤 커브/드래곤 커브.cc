#include <bits/stdc++.h>
using namespace std;

int n, x, y, d, g;

bool grid[101][101];
string dragon;

void move(int d) {
	switch (d) {
	case 0:
		x++;
		break;
	case 1:
		y--;
		break;
	case 2:
		x--;
		break;
	case 3:
		y++;
		break;
	}
	grid[y][x] = 1;
}

void generation() {
	bool init = false;
	grid[y][x] = 1;
	while (g >= 0) {
		g--;
		if (!init) {
			dragon += d + '0';
			move(d);
			init = 1;
		}
		else {
			string temp = "";
			for (int i = dragon.size() - 1; i >= 0; i--) {
				int next = ((dragon[i] - '0') + 1) % 4;

				move(next);
				temp += next + '0';
			}
			dragon += temp;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	while (n--) {
		cin >> x >> y >> d >> g;
		dragon = "";
		generation();
	}
	int ans = 0;
	for (int i = 1; i <= 100; i++)for (int j = 1; j <= 100; j++) {
		if (grid[i - 1][j - 1] && grid[i - 1][j] && grid[i][j - 1] && grid[i][j]) ans++;
	}
	cout << ans;
}