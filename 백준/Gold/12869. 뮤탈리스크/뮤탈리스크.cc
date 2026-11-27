#include <bits/stdc++.h>
using namespace std;

int scv[61][61][61];

int solve(int a, int b, int c) {

	if (scv[a][b][c] != 0)return scv[a][b][c];

	if (a <= 9 && b <= 3 && c <= 1) return scv[a][b][c] = 1;

	int temp = 50;
	vector<int> t = { a, b, c };
	do {
		vector<int> tt;
		tt.push_back(max(0, t[0] - 9));
		tt.push_back(max(0, t[1] - 3));
		tt.push_back(max(0, t[2] - 1));
		sort(tt.rbegin(), tt.rend());

		int x = tt[0], y = tt[1], z = tt[2];
		temp = min(temp, solve(x, y, z));

	} while (prev_permutation(t.begin(), t.end()));

	return scv[a][b][c] = temp + 1;
}

int main() {

	int n;
	cin >> n;

	vector<int> t(3);
	for (int i = 0; i < n; i++) cin >> t[i];

	sort(t.rbegin(), t.rend());
	cout << solve(t[0], t[1], t[2]);

}