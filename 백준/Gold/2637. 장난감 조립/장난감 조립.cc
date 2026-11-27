#include <bits/stdc++.h>
using namespace std;

int main() {
	int target, r, f, t, m, a;
	cin >> target >> r;

	vector<vector<pair<int, int>>> rule(target + 1);
	vector<int> topo(target + 1);
	vector<int> memo(target + 1);
	while (r--) {
		cin >> t >> f >> m;
		topo[f]++;
		rule[t].push_back({ f, m });
	}
	memo[target] = 1;

	queue<int> q;
	q.push(target);
	while (!q.empty()) {
		a = q.front();
		q.pop();
		for (auto i : rule[a]) {
			memo[i.first] += memo[a] * i.second;
			topo[i.first]--;
			if (topo[i.first] == 0)q.push(i.first);
		}
		if (rule[a].size() != 0) memo[a] = 0;
	}

	for (int i = 1; i < target; i++) {
		if (memo[i]) cout << i << ' ' << memo[i] << '\n';
	}
}