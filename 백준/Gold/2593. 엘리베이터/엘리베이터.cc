#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, m;
	cin >> n >> m;

	vector<pair<int, int>> A(m);
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		A[i] = { a, b };
	}

	vector<int> used(n + 1, -1);
	vector<int> dist(n + 1, -1);

	int s, d;
	cin >> s >> d;

	vector<bool> e_used(m);
	queue<tuple<int, int>> q; // 현재 위치, 이용한 엘베 수
	q.push({ s, 0});
	dist[s] = 0;
	while (!q.empty()) {

		int a, b;
		tie(a, b) = q.front();
		q.pop();

		if (a == d) break;
		
		for (int i = 0; i < m; i++) {
			if (e_used[i]) continue;
			
			int x, y;
			tie(x, y) = A[i];

			if (x <= a && (a - x) % y == 0) {
				e_used[i] = 1;
				for (int k = x; k <= n; k += y) {
					if (dist[k] == -1) {
						dist[k] = b + 1;
						used[k] = i;
						q.push({ k, b + 1 });
					}
				}
			}
		}
	}

	if (dist[d] == -1) {
		cout << -1;
		return 0;
	}

	vector<int> ans;
	int c = d;
	while (c != s) {

		int b = used[c];
		ans.push_back(b);

		int x, y;
		tie(x, y) = A[b];

		for (int i = x; i <= n; i += y) {
			if (dist[i] == dist[c] - 1) {
				c = i;
				break;
			}
		}
	}

	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for (int i : ans) cout << i + 1 << '\n';

}