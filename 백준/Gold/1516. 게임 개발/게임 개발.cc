#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, t, a;
	cin >> n;

	vector<int> topo(n + 1);
	vector<int> buildtime(n + 1);
	vector<vector<int>> base(n+1);

	for (int i = 1; i <= n; i++) {
		cin >> buildtime[i];
		cin >> a;
		while (a != -1) {
			base[a].push_back(i);
			topo[i]++;
			cin >> a;
		}
	}

	vector<int> ans(n + 1);

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topo[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		a = q.front();
		q.pop();
		ans[a] += buildtime[a];
		for (int i : base[a]) {
			ans[i] = max(ans[i], ans[a]);
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}
	for (int i = 1; i <= n; i ++ ) {
		cout << ans[i] << '\n';
	}
}