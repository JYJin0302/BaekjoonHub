#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int n) {
	if (n == root[n]) return n;

	return root[n] = find(root[n]);
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n;
	cin >> n;

	priority_queue<tuple<int, int, int>> pq; 

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int a;
			cin >> a;
			if (j > i) {
				pq.push({ -a, i, j });
			}
		}
	}

	root = vector<int>(n+1);
	for (int i = 1; i <= n; i++) root[i] = i;

	vector<pair<int, int>> ans;

	while (!pq.empty()) {

		int a, b, c;
		tie(a, b, c) = pq.top();
		pq.pop();

		if (find(b) != find(c)) {
			ans.push_back({ min(b, c), max(b, c) });
			root[find(b)] = find(c);
		}
	}

	sort(ans.begin(), ans.end());

	for (auto i : ans) {
		cout << i.first << ' ' << i.second << '\n';
	}

}