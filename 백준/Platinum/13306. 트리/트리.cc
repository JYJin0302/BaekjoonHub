#include <bits/stdc++.h>
using namespace std;


vector<int> root;

int find(int n) {
	if (root[n] == n) return n;

	return root[n] = find(root[n]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;

	root = vector<int>(n + 1);
	for (int i = 1; i <= n; i++) root[i] = i;

	vector<int> parent(n+1);
	for (int i = 2; i <= n; i++) cin >> parent[i];

	vector<tuple<int, int, int>> query;
	for (int i = 0; i < n - 1 + q; i++) {
		int t, a, b = 0;
		cin >> t >> a;
		if (t == 1) cin >> b;

		query.push_back({ t, a, b });
	}

	reverse(query.begin(), query.end());

	vector<string> ans;
	for (auto q : query) {
		int t, a, b;
		tie(t, a, b) = q;

		if (t == 1) {

			if (find(a) == find(b)) ans.push_back("YES\n");
			else ans.push_back("NO\n");
		}
		else {
			root[a] = root[parent[a]];
		}
	}

	reverse(ans.begin(), ans.end());
	for (auto i : ans) cout << i;

}