#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

#define mp make_pair
#define x first
#define y second
#define all(x) x.begin(), x.end()

string N[10101];
int E[10101][101];

int root[10101];
int find(int n) {
	if (root[n] == n) return n;
	return root[n] = find(root[n]);
}

void solve() {
	int n, l, k;
	cin >> n >> l >> k;

	for (int i = 0; i < n; i++) {
		cin >> N[i];
		for (int j = 0; j < l; j++) { cin >> E[i][j]; }
	}

	vector<int> val(n, n * 100);
	vector<int> ans(k);

	for (int j = 0; j <= n + 10; j++) root[j] = j;

	int pre = 0;
	vector<bool> used(n);
	for (int f = 0; f < k; f++) {
		// compare with pre

		int ansV = -1;
		int ansi = -1;
		for (int i = 0; i < n; i++) {
			i = find(i);
			if (i == n) break;

			int vval = 0;
			for (int j = 0; j < l; j++) { vval += abs(E[pre][j] - E[i][j]); }

			if (f != 1) val[i] = min(val[i], vval);
			else val[i] = vval;

			if (val[i] > ansV) {
				ansV = val[i];
				ansi = i;
			}
		}

		ans[f] = ansi;
		used[ansi] = 1;
		pre = ansi;
	}

	for (auto f : ans) cout << N[f] << '\n';
}

int main() {
	std::ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t = 1;
	// cin >> t;
	while (t--) { solve(); }
	return 0;
}