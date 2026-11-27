#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<bool> cycle;
vector<bool> visit;

int ss;
bool docycle;
bool finished;

void dfs(int v = 1, int pv = 0) {

	for (int i : adj[v]) {

		if (i != pv) {
			if (visit[i]) {
				ss = i;
				docycle = 1;
				cycle[i] = 1;
				return;
			}
			visit[i] = 1;
			dfs(i, v);

			if (finished) return;
			if (docycle) {
				cycle[i] = 1;
				if (v == ss) finished = 1;
				return;
			}
		}
	}
}

void emptyqueue(queue<pair<int, int>>& a) {
	queue<pair<int, int>> empty;
	swap(a, empty);
}


queue<pair<int, int>> q, tq;
int cnt;
void bfs() {

	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		if (cycle[a]) return;
		for (int i : adj[a]) {
			if (i != b) {
				tq.push({ i, a });
			}
		}
	}

	swap(q, tq);
	cnt++;
	bfs();
}



int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	visit = vector<bool>(n + 1);
	cycle = vector<bool>(n + 1);
	adj = vector<vector<int>>(n + 1);
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	docycle = 0;
	finished = 0;
	visit[1] = 1;

	dfs();

	for (int i = 1; i <= n; i++) {

		if (cycle[i]) cout << "0 ";
		else {
			emptyqueue(q);
			emptyqueue(tq);
			cnt = 0;
			q.push({ i, 0 });
			bfs();
			cout << cnt << ' ';
		}
	}
}