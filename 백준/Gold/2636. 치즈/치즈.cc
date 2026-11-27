// test
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

bool cheese[100][100];
bool visited[100][100];
int sizeOfCheese;
stack<pair<int, int>> st;
int h, w;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

void initialize() {
	for (int i = 0; i < 100; ++i) {
		for (int j = 0; j < 100; ++j) {
			visited[i][j] = false;
		}
	}
}

void bfs(int sy, int sx) {
	queue<pair<int, int>> q;
	visited[sy][sx] = true;
	q.push(make_pair(sy, sx));

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
			if (visited[ny][nx]) continue;
			visited[ny][nx] = true;
			if (cheese[ny][nx]) {
				st.push(make_pair(ny, nx));
			}
			else {
				q.push(make_pair(ny, nx));
			}
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> h >> w;
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			cin >> cheese[i][j];
			if (cheese[i][j]) sizeOfCheese++;
		}
	}

	if (sizeOfCheese == 0) {
		cout << 0 << endl << 0;
		return 0;
	}
	int cnt = 0, ret;
	while (true) {
		initialize();
		cnt++;
		bfs(0, 0);
		if (sizeOfCheese == st.size()) {
			ret = st.size();
			break;
		}
		else {
			while (!st.empty()) {
				int y = st.top().first;
				int x = st.top().second;
				st.pop();
				sizeOfCheese--;
				cheese[y][x] = false;
			}
		}
	}

	cout << cnt << endl << ret;
}
