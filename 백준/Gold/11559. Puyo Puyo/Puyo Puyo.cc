#include <bits/stdc++.h>
using namespace std;

bool change;
vector<string> stage;

bool check[12][6];


void fall() {

	for (int i = 0; i < 6; i++) {

		vector<char> temp;
		for (int j = 11; j >= 0; j--) {
			if (stage[j][i] != '.') {
				
				temp.push_back(stage[j][i]);
				stage[j][i] = '.';
			}
		}

		for (int k = 0; k < temp.size(); k++) {
			stage[11 - k][i] = temp[k];
		}

	}
}

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool inGrid(int x, int y) {
	return x >= 0 && x < 12 && y >= 0 && y < 6;
}

void bfs(int x, int y) {

	int t = 1;
	queue<pair<int, int>> q;
	vector < pair<int, int>> temp;
	temp.push_back({ x, y });
	q.push({ x, y });


	while (!q.empty()) {
		int a, b;
		tie(a, b) = q.front();
		q.pop();

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];
			if (inGrid(na, nb) && stage[na][nb] == stage[x][y] && !check[na][nb]) {
				check[na][nb] = 1;
				q.push({ na, nb });
				temp.push_back({ na, nb });
				t++;
			}
		}
	}

	if (t >= 4) {
		change = 1;
		for (auto i : temp) {
			int a, b;
			tie(a, b) = i;

			stage[a][b] = '.';
		}

	}
}

int main() {

	for (int i = 0; i < 12; i++) {
		string s;
		cin >> s;
		stage.push_back(s);
	}

	int cnt = 0;

	change = 1;
	while (change) {
		change = 0;
		memset(check, 0, sizeof(check));

		for (int i = 0; i < 12; i++) {
			for (int j = 0; j < 6; j++) {
				if (stage[i][j] != '.' && !check[i][j]) {
					check[i][j] = 1;
					bfs(i, j);
				}
			}
		}

		if (change) {
			cnt++;
			fall();
		}
	}

	cout << cnt;
}