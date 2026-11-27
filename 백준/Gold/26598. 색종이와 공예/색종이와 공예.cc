#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
vector<string> A;
bool c[1001][1001];
bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < m;
}

bool check(int i, int j) {

	queue<pair<int, int>> q;
	q.push({ i, j });
	c[i][j] = 1;

	int lm = n+1, lM = -1, rm = m+1, rM = -1;

	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		lm = min(lm, a);
		lM = max(lM, a);
		rm = min(rm, b);
		rM = max(rM, b);

		for (int k = 0; k < 4; k++) {
			int na = a + dx[k];
			int nb = b + dy[k];

			if (inGrid(na, nb) && !c[na][nb] && A[na][nb] == A[i][j]) {
				c[na][nb] = 1;
				q.push({ na, nb });
			}
		}
	}


	for (int ti = lm; ti <= lM; ti++) {
		for (int tj = rm; tj <= rM; tj++) {
			if (A[ti][tj] != A[i][j]) return 0;
		}
	}
	return 1;

}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;

	A = vector<string>(n);
	for (auto& i : A) cin >> i;

	bool valid = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {

			if (!c[i][j]) {
				valid = valid && check(i, j);
			}
		}
	}

	if (valid) cout << "dd";
	else cout << "BaboBabo";

}