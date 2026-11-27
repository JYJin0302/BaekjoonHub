#include <bits/stdc++.h>
using namespace std;

int n, a, ans, temp;
vector<vector<int>> base;
vector<vector<int>> rebase;
vector<int> nodes;
vector<int> cost;
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
	temp = min(temp, cost[v]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		cost.push_back(a);
	}

	base = vector<vector<int>>(n);
	rebase = vector<vector<int>>(n) ;


	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				base[i].push_back(j);
				rebase[j].push_back(i);
			}
		}
	}

	check = vector<bool>(n);
	for (int i = 0; i < n; i++) {
		if (check[i]) continue;
		check[i] = 1;
		dfs1(i);
	}
    
    ans = 0;
	check = vector<bool>(n);
	for (int i =  n -1; i >= 0; i--) {
        int t = nodes[i];
		if (check[t]) continue;
		check[t] = 1;
		temp = 1000001;
		dfs2(t);
		ans += temp;
	}

	cout << ans;
}