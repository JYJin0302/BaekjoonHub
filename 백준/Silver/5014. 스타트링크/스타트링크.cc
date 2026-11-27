#include <bits/stdc++.h>
using namespace std;
#define INF 1000001
int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int f, s, g, u, d;
	cin >> f >> s >> g >> u >> d;

	vector<int> path(f + 1, INF);
	path[s] = 0;

	queue<int> q;  // 층
	q.push(s);
	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (a == g) break;

		if (a + u <= f && path[a + u] == INF) {
			path[a + u] = path[a] + 1;
			q.push(a + u);
		}
		
		if (a - d >= 1 && path[a - d] == INF) {
			path[a - d] = path[a] + 1;
			q.push(a - d);
		}
	}

	if (path[g] == INF) cout << "use the stairs";
	else cout << path[g];
}