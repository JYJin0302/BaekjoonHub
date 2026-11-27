#include <bits/stdc++.h>
#include <random>
using namespace std;

int n;
bool v[1001][1001][3];

bool inRange(int x, int y) {
	return x > 0 && x <= n && y > 0 && y <= n; 
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;

	vector<pair<int, int>> move;
	move.push_back({ 0, 0 });
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		move.push_back({ a, b });
	}

	map<pair<int, int>, bool> vs;
	for (auto i : move) {
		int ta = ax + i.first;
		int tb = ay + i.second;
		
		if (inRange(ta, tb)) vs[{ta, tb}] = 1;
	}

	bool found = 0;
	for (auto i : move) {
		int ta = bx - i.first;
		int tb = by - i.second;

		if (vs[{ta, tb}]) found = 1;
	}

	if (found) {
		cout << "Alice wins";
		return 0;
	}

	if (n < 1000) {

		queue<tuple<int, int, int>> q;
		q.push({ bx, by, 0 });
		v[bx][by][0] = 1;
		while (!q.empty()) {

			int a, b, c;
			tie(a, b, c) = q.front();
			q.pop();

			if (c == 2) continue;

			for (auto i : move) {
				int ta = a + i.first;
				int tb = b + i.second;
				
				if (inRange(ta, tb) && !v[ta][tb][c + 1]) {
					v[ta][tb][c + 1] = 1;
					q.push({ ta, tb, c + 1 });
				}
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {

				bool ok = 1;
				for (int k = 0; k < 3; k++) {
					if (v[i][j][k]) ok = 0;
				}

				if (ok) {
					cout << "tie " << i << ' ' << j;
					return 0;
				}
			}
		}

		cout << "Bob wins";
		return 0;
	}

	mt19937 engine((unsigned int)time(NULL));                    // MT19937 난수 엔진
	uniform_int_distribution<int> distribution(1, n);       // 생성 범위
	auto generator = bind(distribution, engine);

	vs.clear();
	for (auto i : move) {
		int ta = bx + i.first;
		int tb = by + i.second;

		if (inRange(ta, tb)) vs[{ta, tb}] = 1;
	}

	int cnt = 50;
	while (cnt--) {

		int tx = generator();
		int ty = generator();

		bool found = 0;
		for (auto i : move) {
			int ta = tx - i.first;
			int tb = ty - i.second;

			if (vs[{ta, tb}]) {
				found = 1;
				break;
			}
		}

		if (!found) {
			cout << "tie " << tx << ' ' << ty;
			return 0;
		}
	}
	cout << "Bob wins";
}