#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define mp make_pair

int C[4][1010];
int P[2][1010];

int main() {
	int n, m;
	cin >> n >> m;

	int K = 4, mX = 3;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < K; j++) {
			cin >> C[j][i];
		}
	}

	for (int i = 0; i < n; i++) {
		cin >> P[0][i] >> P[1][i];
		P[0][i]--, P[1][i]--;
	}

	vector<pair<pair<int, int>, int>> edg;
	for (int i = 0; i < m; i++) {
		int a, b, t;
		cin >> a >> b >> t;
		a--, b--, t--;
		edg.push_back(mp(mp(a, b), t));
	}

	for (int i = 0; i < (1 << n); i++) {
		bool ok = 1;
		vector<int> pos(n, -1);
		for (int j = 0; j < n; j++) {
			int us = 0;
			if (i & (1 << j)) us = P[1][j];
			else us = P[0][j];

			if (pos[us] != -1) ok = 0;
			pos[us] = j;
		}

		if (!ok) continue;

		for (auto f : edg) {
			auto [u, v] = f.first;
			int t = f.second;

			ok &= (C[t][pos[u]] == C[t][pos[v]]);
		}
		if (ok) {
			cout << "YES\n";
			for (int j = 0; j < n; j++) {
				cout << pos[j]+1 << ' ';
			}
			return 0;
		}
	}
	cout << "NO\n";
}