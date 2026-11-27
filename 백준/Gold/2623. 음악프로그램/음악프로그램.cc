#include <bits/stdc++.h>
using namespace std;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, a;
	cin >> n >> m;
	vector<int> topo(n+1);
	vector<vector<int>> base(n + 1);
	vector<int> ans;
	for (int i = 0; i < m; i++) {
		cin >> a;
		vector<int> temp(a);
		for (auto& i : temp) cin >> i;

		for (int i = 1; i < a; i++) {
			base[temp[i - 1]].push_back(temp[i]);
			topo[temp[i]]++;
		}
	}

	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (topo[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		a = q.front();
		q.pop();
		ans.push_back(a);
		for (int i : base[a]) {
			topo[i]--;
			if (topo[i] == 0) q.push(i);
		}
	}
	
	if (ans.size() != n) cout << 0;
	else {
		for (int i : ans) cout << i << '\n';
	}

}