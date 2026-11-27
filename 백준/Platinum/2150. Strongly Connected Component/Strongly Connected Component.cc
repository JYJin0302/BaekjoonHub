#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
vector<vector<int>> base;
vector<vector<int>> rebase;
vector<int> nodes;
vector<vector<int>> ans;

vector<int> temp;
vector<bool> check;


void dfs1(int v = 0) {
	for (int i : base[v]) {
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}
	nodes.push_back(v);
}

void dfs2(int v = 0) {

	for (int i : rebase[v]) {
		if (check[i]) continue;
		check[i] = 1;
		dfs2(i);
	}
	temp.push_back(v);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);


	cin >> n >> m;
	
	base = vector<vector<int>>(n+1);
	rebase = vector<vector<int>>(n+1);

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		base[a].push_back(b);
		rebase[b].push_back(a);
	}

	check = vector<bool>(n+1);
	for (int i = 1; i <= n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}


	check = vector<bool>(n+1);
	for (int i = n - 1; i >= 0; i--) {
		int t = nodes[i];
		if (check[t]) continue;
		check[t] = 1;

		dfs2(t);
		
		sort(temp.begin(), temp.end());
		ans.push_back(temp);
		temp.clear();
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << '\n';
	for (auto i : ans) {
		for (int k : i) cout << k << ' ';
		cout << "-1\n";
	}

}