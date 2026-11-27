#include <bits/stdc++.h>
using namespace std;

int r, c, m;
int grid[100][100];

vector<bool> eaten;
bool ok;

struct Shark {
	int size;
	int x, y;
	int face; // 1: up, 2: down, 3: right, 4: left
	int speed;

	void move() {
		int cnt = speed;
		int a, b;
		switch (face) {
		case 1:
			a = x;

			if (cnt <= a) {
				x = a - cnt;
			}
			else if (cnt >= a + r - 1) {
				x = r - 1 - (cnt - r + 1 - a);
			}
			else {
				x = cnt - a;
				face = 2;
			}
			break;
		case 2:
			a = x;

			if (cnt <= r - 1 - a) {
				x = cnt + a;
			}
			else if (cnt >= 2*r - 2 - a) {
				x = cnt - 2 * r + 2 + a;
			}
			else {
				x = r - 1 -(a + cnt - r + 1);
				face = 1;
			}
			break;
		case 3:
			a = y;

			if (cnt <= c - 1 - a) {
				y = cnt + a;
			}
			else if (cnt >= 2 *c - 2 - a) {
				y = cnt - 2 * c + 2 + a;
			}
			else {
				y = c - 1 - (a + cnt - c + 1);
				face = 4;
			}
			break;
		case 4:
			a = y;

			if (cnt <= a) {
				y = a - cnt;
			}
			else if (cnt >= a + c - 1) {
				y = c - 1 - (cnt - c + 1 - a);
			}
			else {
				y = cnt - a;
				face = 3;
			}
			break;
		}

		if (grid[x][y] > size) {
			ok = false;
		}
		else {
			
			grid[x][y] = size;
		}
	}
};

bool comp(Shark& s1, Shark& s2) {
	return s1.size > s2.size;
}

vector<Shark> shark;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	cin >> r >> c >> m;

	for (int i = 0; i < m; i++) {
		int x1, x2, x3, x4, x5;
		cin >> x1 >> x2 >> x3 >> x4 >> x5;
		Shark t;
		t.x = x1 - 1;
		t.y = x2 - 1;
		t.speed = x3;
		t.face = x4;
		if (x4 == 1 || x4 == 2) t.speed %= (r - 1) * 2;
		else t.speed %= (c - 1) * 2;
		t.size = x5;
		shark.push_back(t);
		grid[t.x][t.y] = t.size;
	}

	eaten = vector<bool>(m);
	sort(shark.begin(), shark.end(), comp);

	int ans = 0;

	for (int man = 0; man < c; man++) {
		int cx = 1000, cy = man;
		for (int i = 0; i < m; i++) {
			if (shark[i].y == man && !eaten[i]) {
				cx = min(cx, shark[i].x);
			}
		}
		if (cx != 1000) {
			ans += grid[cx][cy];
		}
		for (int i = 0; i < m; i++) {
			grid[shark[i].x][shark[i].y] = 0;
			if (shark[i].x == cx && shark[i].y == cy) {
				eaten[i] = 1;
			}
		}

		for (int i = 0; i < m; i++) {
			if (eaten[i]) continue;
			ok = true;
			shark[i].move();
			if (!ok) eaten[i] = 1;
		}
	}
	cout << ans;
}