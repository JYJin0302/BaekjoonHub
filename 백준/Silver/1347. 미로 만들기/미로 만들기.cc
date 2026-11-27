#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool vis[202][202];

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	int dir = 2;
	int x = 100, y = 100;

	int xl, xr;
	xl = xr = x;
	int yl, yr;
	yl = yr = y;

	vis[x][y] = 1;
	for (char c : s) {
		if (c == 'L') {
			dir = (dir + 3) % 4;
		} else if (c == 'R') {
			dir = (dir + 1) % 4;
		} else {
			x += dx[dir];
			y += dy[dir];
			vis[x][y] = 1;

			xl = min(xl, x);
			xr = max(xr, x);
			yl = min(yl, y);
			yr = max(yr, y);
		}
	}

	for(int i = xl; i <= xr; i++){
		for(int j = yl; j <= yr; j++){
			if (vis[i][j]) cout << '.';
			else cout << "#";
		}
		cout << '\n';
	}

}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	for (int i = 1; i <= t; i++) { solve(); }
	return 0;
}