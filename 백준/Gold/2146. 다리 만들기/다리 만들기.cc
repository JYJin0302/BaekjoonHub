#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans, cnt;
int grid[100][100];
vector<vector<bool>> check;
vector < vector<bool>> done;
queue<pair<int, int>> q;
queue<pair<int, int>> tq;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };

bool validpos(int r, int c) {
	return (r >= 0 && r < n&& c >= 0 && c < n);
}
void clearqueue(queue<pair<int, int>> &s) {
	queue<pair<int, int>> emp;
	swap(emp, s);
}

void bfs() {
	while (!q.empty()) {
		tie(a, b) = q.front();
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ta = a + dx[i];
			int tb = b + dy[i];
			if (validpos(ta, tb) && !check[ta][tb]) {

				if (cnt == 0 && grid[ta][tb] == 1) {
					done[ta][tb] = 1;
					q.push({ ta, tb });
				}
				else if (grid[ta][tb] == 1) {
					return;
				}
				else {
					tq.push({ ta, tb });
				}
				check[ta][tb] = 1;
			}
		}
	}

	swap(tq, q);
	if (q.empty()) return;
	cnt++;
	bfs();
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> grid[i][j];
		}
	}
    
	done = vector<vector<bool>>(n, vector<bool>(n));
	ans = 100000;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!done[i][j] && grid[i][j] == 1) {
				done[i][j] = 1;
				cnt = 0;
				q.push({ i, j });
                check = vector<vector<bool>>(n, vector<bool>(n));
                check[i][j] = 1;
				bfs();

				
				ans = min(ans, cnt);					
				clearqueue(q);
				clearqueue(tq);
			}
		}
	}
	
	cout << ans;

}