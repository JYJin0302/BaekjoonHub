#include <bits/stdc++.h>
using namespace std;

vector<int> root;

int find(int x) {
	if (root[x] == x) return x;

	return root[x] = find(root[x]);
}

double dist(pair<int, int> x, pair<int, int> y) {
	return sqrt(pow(x.first - y.first, 2) + pow(x.second - y.second, 2));
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	cout << setprecision(2) << fixed;

	int t;
	cin >> t;
	while (t--) {

		int s, p;
		cin >> s >> p;

		vector<pair<int, int>> A(p);
		for (int i = 0; i < p; i++) {
			cin >> A[i].first >> A[i].second;
		}

		vector<tuple<double, int, int>> edge;
		for (int i = 0; i < p; i++) {
			for (int j = i + 1; j < p; j++) {
				edge.push_back({ dist(A[i], A[j]), i, j });
			}
		}

		sort(edge.begin(), edge.end());

		root = vector<int>(p);
		for (int i = 0; i < p; i++) root[i] = i;

		vector<double> ans;

		for (auto i : edge) {
			double d;
			int a, b;
			tie(d, a, b) = i;

			find(a), find(b);
			if (root[a] != root[b]) {
				ans.push_back(d);
				root[root[a]] = root[b];
			}
		}

		sort(ans.begin(), ans.end());

		int cnt = 0;
		while (!ans.empty() && cnt < s - 1) {
			ans.pop_back();
			cnt++;
		}

		if (ans.empty()) cout << "0.00\n";
		else cout << ans.back() << '\n';
	}
}