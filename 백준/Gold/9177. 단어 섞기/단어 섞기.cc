#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bool visited[201][201];
	int t;
	cin >> t;
	for(int tt = 1; tt <= t; tt++) {

		string s1, s2, st;
		cin >> s1 >> s2 >> st;

		bool ok = 0;
		memset(visited, 0, sizeof(visited));

		queue<pair<int, int>> q;
		q.push({ 0, 0 });
		visited[0][0] = 1;
		while (!q.empty()) {

			int a, b;
			tie(a, b) = q.front();
			q.pop();

			if (a == s1.size() && b == s2.size()) {
				ok = 1;
				continue;
			}
			int c = a + b;
			if (a != s1.size() && st[c] == s1[a] && !visited[a + 1][b]) {
				visited[a + 1][b] = 1;
				q.push({ a + 1, b });
			}
			if (b != s2.size() && st[c] == s2[b] && !visited[a][b + 1]) {
				visited[a][b + 1] = 1;
				q.push({ a, b + 1 });
			}

		}

		cout << "Data set " << tt << ": " << (ok ? "yes" : "no") << '\n';
	}
}