#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n;
int areaNum[11][11];
int areaAdj[11][11];
bool fin[11][11];
vector<pair<int, int>> lst;
map<pair<int, int>, int> ldx;

bool inGrid(int x, int y) {
	return x >= 0 && x < n&& y >= 0 && y < n;
}

int dp[1 << 20];

int getGnum(int s) {
	int sz = lst.size();

	if (dp[s] != -1) return dp[s];
	if (s + 1 == (1 << sz)) return dp[s] = 0;

	map<int, bool> cnt;
	for (int i = 0; i < sz; i++) {
		if (s & (1 << i)) continue;

		// i 자리에 설치
		int ts = s;
		ts += (1 << i);

		int a, b;
		tie(a, b) = lst[i];

		for (int j = 0; j < 4; j++) {
			int na = a + dx[j];
			int nb = b + dy[j];

			int tx = ldx[{na, nb}] - 1;

			if (tx >= 0 && (ts &(1 << tx)) == 0) {
				ts += 1 << tx;
			}
		}
		cnt[getGnum(ts)] = 1;
	}

	int res = 0;
	while (cnt[res]) res++;
	return dp[s] = res;
}

int f(int x, int y) {

	lst.clear(); 
	ldx.clear();

	queue<pair<int, int>> q;
	q.push({ x, y });
	fin[x][y] = 1;
	while (!q.empty()) {
		int a, b;
		tie(a, b) = q.front();
		q.pop();

		lst.push_back({ a, b });

		for (int i = 0; i < 4; i++) {
			int na = a + dx[i];
			int nb = b + dy[i];

			if (inGrid(na, nb) && !fin[na][nb] && areaAdj[na][nb] == areaAdj[a][b]) {
				fin[na][nb] = 1;
				q.push({ na,nb });
			}
		}
	}

	for (int i = 0; i < lst.size(); i++) {
		ldx[lst[i]] = i + 1;
	}
	
	for (int i = 0; i < (1 << lst.size()); i++) dp[i] = -1;

	return getGnum(0);
}

void solve() {

	cin >> n;

	vector<string> A(n);
	for (auto& i : A) cin >> i;

	int areaCnt = 0;
	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (A[i][j] == '*' && areaNum[i][j] == 0) {

				areaNum[i][j] = ++areaCnt;
				q.push({ i, j });
				while (!q.empty()) {
					int a, b;
					tie(a, b) = q.front();
					q.pop();

					for (int k = 0; k < 4; k++) {
						int na = a + dx[k];
						int nb = b + dy[k];

						if (inGrid(na, nb)) {
							if (A[na][nb] == '*' && areaNum[na][nb] == 0) {
								areaNum[na][nb] = areaCnt;
								q.push({ na, nb });
							}
							else if (A[na][nb] == '.') {
								areaAdj[na][nb] = areaCnt;
							}
						}
					}
				}
			}
		}
	}

	int gNum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (areaAdj[i][j] != 0 && !fin[i][j]) {
				int tval = f(i, j);
				gNum ^= tval;
			}
		}
	}

	if (gNum == 0) cout << "Second player will win";
	else cout << "First player will win";
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);

	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
}