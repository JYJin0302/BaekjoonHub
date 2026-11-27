#include <bits/stdc++.h>
using namespace std;

bool cmp(tuple<int, int, int>& a, tuple<int, int, int>& b) {
	return get<1>(a) < get<1>(b);
}


int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
	int n, c, m, x, y, b;
	cin >> n >> c >> m;

	vector<tuple<int, int, int>> A;
	for (int i = 0; i < m; i++) {
		cin >> x >> y >> b;
		A.push_back({ x, y, b });
	}

	sort(A.begin(), A.end(), cmp);

	vector<int> capa(n + 1);

	int ans = 0;

	for (auto i : A) {
		tie(x, y, b) = i;
		int temp = 100000;
		for (int k = x; k < y; k++) {
			temp = min(temp, c - capa[k]);
		}

		for (int k = x; k < y; k++) {
			capa[k] += min(temp, b);
		}
		ans += min(temp, b);
	}

	cout << ans;

}