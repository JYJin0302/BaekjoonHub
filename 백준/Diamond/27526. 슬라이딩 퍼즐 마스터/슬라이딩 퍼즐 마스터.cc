#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> A;
vector<vector<int>> ans;

vector<vector<int>> tmp[10];

void solve(int s) {

	if (s == 1) {
		vector<int> res = { 1 };
		tmp[s].push_back(res);
		return;
	}

	int ix = 0, t = 0;

	while (ix < tmp[s - 1].size()) {

		vector<int> tt;
		// tt : 0, 1, 2, 3, ... ,s-1, + s

		if (t == 0) {
			tt = tmp[s - 1][ix];
			tt.push_back(s);

			tmp[s].push_back(tt);
			for (int i = s - 1; i > 0; i--) {
				swap(tt[i], tt[i - 1]);
				tmp[s].push_back(tt);
			}
		}
		else {
			tt.push_back(s);
			for (auto i : tmp[s - 1][ix]) tt.push_back(i);
			tmp[s].push_back(tt);

			for (int i = 0; i < s - 1; i++) {
				swap(tt[i], tt[i + 1]);
				tmp[s].push_back(tt);
			}
		}

		ix++;
		t = 1 - t;
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	int sz = n * m;
	A = vector<int>(sz);
	for (int i = 0; i < sz; i++) A[i] = i;

	for (int i = 1; i <= sz; i++) solve(i);

	/*for (int i = 1; i <= sz; i++) {
		cout << "SOLVE " << i << '\n';
		for (auto j : tmp[i]) {
			for (auto k : j) cout <<k << ' ';
			cout << '\n';
		}
	}*/

	vector<int> qq(sz);
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			for (int j = 0; j < m; j++) qq[i * m + j] = (i + 1) * m - j;
		}
		else for (int j = 0; j < m; j++) qq[i * m + j] = i * m + j + 1;
	}
	int st = 0;
	for (;; st++) {
		bool fl = 1;
		for (int i = 0; i < sz; i++) {
			if (tmp[sz][st][i] != qq[i]) {
				fl = 0;
				break;
			}
		}
		if (fl) break;
	}
	int szz = tmp[sz].size();
	for (int i = 0; i < szz; i++) {
		int idx = (i + st) % szz;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				int tt = tmp[sz][idx][qq[j * m + k] - 1];
				if (tt == sz) cout << '#';
				else cout << tt;
				int qqqqq = 0;
			}
			cout << '\n';
		}
	}
}